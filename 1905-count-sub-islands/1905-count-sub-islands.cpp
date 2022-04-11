class Solution {
public:
    void solver(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j,int &flag)
    {
        if(i<0 || j<0 || i>=grid1.size()||j>=grid1[0].size()||grid2[i][j]!=1)
            return;
        
        if(grid2[i][j]==1 && grid1[i][j]==0)
        {
            flag=1;
            return;
        }
        
        grid2[i][j]=0;
        
        solver(grid1,grid2,i+1,j,flag);
        solver(grid1,grid2,i,j+1,flag);
        solver(grid1,grid2,i-1,j,flag);
        solver(grid1,grid2,i,j-1,flag);
       
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                int flag=0;
                if(grid2[i][j]==1)
                {
                    solver(grid1,grid2,i,j,flag);
                    if(flag==0)
                    {
                        res++;
                    }
                }
                
            }
        }
        
        return res;
    }
};