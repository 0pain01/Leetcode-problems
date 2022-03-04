class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int q= query_row;
        double dp[q+2][q+2];
        
        for(int i=0;i<q+2;i++)
        {
            for(int j=0;j<q+2;j++)
            {
                dp[i][j]=0;
            }
        }
        
        dp[0][0]=poured;
        int g= query_glass;
        
        for(int i=0;i<q+1;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(dp[i][j]>=1)
                {
                    double amt = (dp[i][j]-1)/2;
                    dp[i][j]=1;
                    
                    dp[i+1][j]+=amt;
                    dp[i+1][j+1]+=amt;
                }
            }
        }
        
        return dp[q][g];
    }
};