// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void util(int W,int wt[],int val[],int n,int **dp)
    {
        
        if(wt[n-1]<=W)
        {
            dp[n][W] = max(val[n-1]+ dp[n][W-wt[n-1]],dp[n-1][W]);
        }
        
        else if(wt[n-1]>W)
        {
            dp[n][W] = dp[n-1][W];
        }
        
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        int** dp= new int*[n+1];
        
        for(int i=0;i<=n;i++)
            dp[i]=new int[W+1];
        
        for (int i = 0; i <=n; i++)
            for (int j = 0; j <W+1 ; j++)
                dp[i][j] = -1;
                
            for(int i=0;i<W+1;i++)
            {
                dp[0][i]=0;
            }
            
            for(int i=0;i<=n;i++)
            {
                dp[i][0]=0;
            }
                
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<W+1;j++)
           {
               util(j,wt,val,i,dp);
           }
       }
       
        return dp[n][W];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends