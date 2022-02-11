class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        
        string s1 = s;
        
        reverse(s1.begin(),s1.end());
        
        if(s1==s)
            return 0;
        
        //int n = s.size();
        int m = s1.size();
        int** dp=new int*[n+1];
        
        for(int i=0;i<=n;i++)
            dp[i]=new int[m+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=-1;
        
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==s1[j-1])
                    dp[i][j]= 1+ dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        //return dp[n][m];
        
        return n- dp[n][m];
    }
};