// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solver(int arr[],int i, int j,int **dp)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
         
        int mn = INT_MAX;  
        for(int k = i;k<=j-1;k++)
        {
            int temp = solver(arr,i,k,dp) + solver(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            if(temp<mn)
                mn = temp;
        }
        dp[i][j]=mn;
        
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N-1;
        
        int** dp = new int*[N+1];
        
        for(int i=0;i<=N;i++)
            dp[i]=new int[N+1];
            
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                dp[i][j]=-1;
        
        return solver(arr,i,j,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends