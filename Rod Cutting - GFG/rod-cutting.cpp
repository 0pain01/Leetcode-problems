// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    void solver(int p,int piece[],int price[],int n,int **dp)
    {
        if(piece[n-1]<=p)
        {
            dp[n][p] = max(price[n-1]+ dp[n][p-piece[n-1]],dp[n-1][p]);
        }
        
        else if(piece[n-1]>p)
        {
            dp[n][p] = dp[n-1][p];
        }
    }
    
    int cutRod(int price[], int n) {
        //code here
        int piece[n];
        
        for(int i=0;i<n;i++)
            piece[i]=i+1;
            
        int** dp = new int*[n+1];
        
        for(int i=0;i<=n;i++)
            dp[i]=new int[n+1];
            
        for (int i = 0; i <=n; i++)
            for (int j = 0; j <n+1 ; j++)
                dp[i][j] = -1;
                
            for(int i=0;i<n+1;i++)
            {
                dp[0][i]=0;
            }
            
            for(int i=0;i<=n;i++)
            {
                dp[i][0]=0;
            }
                
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<n+1;j++)
           {
               solver(j,piece,price,i,dp);
           }
       }
       
       return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends