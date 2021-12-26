class Solution {
public:

    
    string longestPalindrome(string s) {
        int n = s.size();
        
        string s1="";
        
        if(n==1)
            return s;
        
        if(n==2)
            if(s[0]==s[1])
                return s;
            else
                return (s1+=s[0]);
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        int maxl=1,maxi=0,maxj=0;
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                {
                    dp[i][i+1]=1;
                    maxi=i;
                    maxl=2;
                }
        }
        
        
        for (int k = 3; k <= n; ++k) {
        
        for (int i = 0; i < n - k + 1; ++i) {
            
            int j = i + k - 1;
 
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = 1;
 
                if (k > maxl) {
                    maxi = i;
                    maxl = k;
                }
            }
        }
    }
        
  
        for(int i=maxi;i<=maxi+maxl-1;i++)
            s1+=s[i];
        
        return s1;
    }
};