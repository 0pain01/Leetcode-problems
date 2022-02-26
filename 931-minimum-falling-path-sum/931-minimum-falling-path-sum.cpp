class Solution {
public:
 
    void solver(vector<vector<int>>matrix,int**dp,int n)
    {
          for(int i=1;i<n;i++)
          {
              for(int j=0;j<n;j++)
              {
                  int x=matrix[i][j];
                  if(j==0)
                  {
                      dp[i][j]=min(dp[i-1][j]+x,dp[i-1][j+1]+x);
                  }
                  else if(j==n-1)
                  {
                      dp[i][j]=min(dp[i-1][j]+x,dp[i-1][j-1]+x);
                  }
                  else
                  {
                      int mn = min(dp[i-1][j],dp[i-1][j-1]);
                      mn= min(mn,dp[i-1][j+1]);
                      dp[i][j]=mn+x;
                  }
              }
          }
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int **dp = new int *[n];
        for(int i=0;i<n;i++)
            dp[i]=new int[n];
        
        for(int i=0;i<n;i++)
            dp[0][i]=matrix[0][i];
        
        solver(matrix,dp,n);
        
        int mn =INT_MAX;
        
        for(int i=0;i<n;i++)
            if(mn>dp[n-1][i])
                mn=dp[n-1][i];
        
        return mn;
    }
};