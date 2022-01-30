// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
 
    void util(int W,int wt[],int val[],int n,int **dp)
    {
        
        if(wt[n-1]<=W)
        {
            dp[n][W] = max(val[n-1]+ dp[n-1][W-wt[n-1]],dp[n-1][W]);
        }
        
        else if(wt[n-1]>W)
        {
            dp[n][W] = dp[n-1][W];
        }
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
        int** dp;
        dp = new int*[n+1];
        
    
        for (int i = 0; i <=n; i++)
            dp[i] = new int[W + 1];
 
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

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends