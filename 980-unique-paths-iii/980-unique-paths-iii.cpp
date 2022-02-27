class Solution {
public:
    int dx[4]={-1,0,1, 0};
    int dy[4]={ 0,1,0,-1};
    void solver(int i,int j,int cnt,int &ans,vector<vector<int>>grid)
    {
        
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size() || grid[i][j]==-1)
            return;
        
        if(cnt==0 && grid[i][j]==2)
        {
            ans=ans+1;
            return;
        }
        
        for(int k=0;k<4;k++)
        {
            grid[i][j]=-1;
            solver(i+dx[k],j+dy[k],cnt-1,ans,grid);
            grid[i][j]=0;
        }
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int starti=0,startj=0,endi=0,endj=0;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    starti=i,startj=j;
                if(grid[i][j]==2)
                    endi=i,endj=j;
                if(grid[i][j]==0)
                    cnt++;
            }
        }
     
        cnt=cnt+1;
        int ans=0;
        solver(starti,startj,cnt,ans,grid);
        
        return ans;
    }
};