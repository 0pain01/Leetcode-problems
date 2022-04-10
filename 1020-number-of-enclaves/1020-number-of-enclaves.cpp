class Solution {
public:
    void solver(vector<vector<int>>&grid,int i, int j,int &flag,int &cnt)
    {
        if(i<1 || j<1||i>=grid.size()-1|| j>=grid[0].size()-1)
        {
            if(i==0 || j==0||i==grid.size()-1 ||j==grid[0].size()-1)
                if(grid[i][j]==1)
                    flag=1;
            return;
        }
        if(grid[i][j]==0 || grid[i][j]==-1)
            return;
        
        grid[i][j]=-1;
        cnt++;
        
        solver(grid,i+1,j,flag,cnt);
        solver(grid,i-1,j,flag,cnt);
        solver(grid,i,j+1,flag,cnt);
        solver(grid,i,j-1,flag,cnt);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        int res=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                int flag=0;cnt=0;
                if(grid[i][j]==1)
                {
                    solver(grid,i,j,flag,cnt);
                    if(flag==0)
                        res+=cnt;
                }
            }
        }
        
        return res;
    }
};