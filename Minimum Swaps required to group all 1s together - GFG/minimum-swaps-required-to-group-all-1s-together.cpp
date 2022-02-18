// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    int sum=0,mx=0;
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            cnt1++;
    }
    if(cnt1==0)
        return -1;
    for(int i=0;i<cnt1;i++)
    {
        if(arr[i]==1)
            sum++;
    }
    mx=sum;
    for(int i=cnt1;i<n;i++)
    {
        sum =sum + arr[i]-arr[i-cnt1];
        if(mx<sum)
            mx=sum;
    }
    return cnt1-mx;
}