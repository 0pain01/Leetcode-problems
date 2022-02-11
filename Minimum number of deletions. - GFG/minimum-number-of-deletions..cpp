// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string str, int n) { 
    
        string s1 = str;
        
        reverse(s1.begin(),s1.end());
        
        if(s1==str)
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
                if(str[i-1]==s1[j-1])
                    dp[i][j]= 1+ dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n- dp[n][m];
} 