// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size();
	    int m = str2.size();
	    
	    int** dp = new int*[n+1];
	    
	    for(int i=0;i<=n;i++)
	        dp[i]=new int[m+1];
	        
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0 || j==0)
	                dp[i][j]=0;
	            else 
	                dp[i][j]=-1;
	        }
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j]= 1+ dp[i-1][j-1];
	            }
	            
	            else
	            {
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    
	    int x = m + n - (2*dp[n][m]);
	    
	    return x;
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends