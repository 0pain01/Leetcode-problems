class Solution {
public:
    int solver(int **dp,int m,int n)
    {
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        int **dp = new int *[m];
        
        for(int i=0;i<m;i++)
            dp[i]= new int[n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(i==0 || j==0)
                    dp[i][j]=1;
                
        return solver(dp,m,n);
        
    }
};