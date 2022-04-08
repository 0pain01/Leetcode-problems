class Solution {
public:
    void solver(vector<vector<int>>&grid,int i,int j,int &cnt)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==2)
            return;
        
        grid[i][j]=2;
        cnt+=1;
        
        solver(grid,i-1,j,cnt);
        solver(grid,i,j-1,cnt);
        solver(grid,i+1,j,cnt);
        solver(grid,i,j+1,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx=0;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt=0;
                if(grid[i][j]==1)
                {
                    solver(grid,i,j,cnt);
                    if(mx<cnt)
                        mx=cnt;
                }
            }
        }
        
        return mx;
    }
};