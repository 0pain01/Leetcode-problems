class Solution {
public:
    int dx[4]={-1,0,1, 0};
    int dy[4]={ 0,1,0,-1};
    void solver(int i,int j,int endi,int endj,int m,int n,int cnt,int &ans,vector<vector<int>>grid)
    {
        
        if(i<0 || j<0 || i>=m|| j>=n || grid[i][j]==-1)
            return;
        
        if(cnt==0 && i==endi && j==endj)
        {
            ans=ans+1;
            return;
        }
        
        for(int k=0;k<4;k++)
        {
            grid[i][j]=-1;
            solver(i+dx[k],j+dy[k],endi,endj,m,n,cnt-1,ans,grid);
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
        solver(starti,startj,endi,endj,m,n,cnt,ans,grid);
        
        return ans;
    }
};