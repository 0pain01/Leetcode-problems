// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
  #define ll long long int
    
    void solver(int s, int S[],int n,ll** dp)
    {
        if(S[n-1]<=s)
            dp[n][s]= dp[n][s-S[n-1]] + dp[n-1][s];
        else
            dp[n][s] = dp[n-1][s];
    }
    
    
    long long int count(int S[], int m, int n) {
        
        ll** dp = new ll*[m+1];
        for(int i=0;i<=m;i++)
            dp[i]=new ll[n+1];
            
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
                
        for(int i=0;i<=m;i++)
            dp[i][0]=1;
            
        for(int i=1;i<=n;i++)
            dp[0][i]=0;
            
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                solver(j,S,i,dp);
                
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends