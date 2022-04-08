class Solution {
public:
    void solver(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size()||grid[i][j]=='0'||grid[i][j]=='#')
            return ;
        
        grid[i][j]='#';
        
        solver(grid,i+1,j);
        solver(grid,i,j+1);
        solver(grid,i-1,j);
        solver(grid,i,j-1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    solver(grid,i,j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};