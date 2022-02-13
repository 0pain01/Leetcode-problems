// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    string str1=str;
            int m = n;
        
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
                    if(str[i-1]==str1[j-1] && (i!=j))
                        dp[i][j]= 1+ dp[i-1][j-1];
                    else
                        dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        
            return dp[n][m];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends