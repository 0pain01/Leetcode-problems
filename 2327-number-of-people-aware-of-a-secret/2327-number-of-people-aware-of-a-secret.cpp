class Solution {
public:

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long>arr(n+1);
        arr[0]=0,arr[1]=1;//day 1 only one knows the secret
        
        int p=0;
        // p is no of people know the secret at ith day
        
        int mod = 1e9+7;
        for(int i=2;i<=n;i++)
        {
            arr[i]=p=(p+arr[max(0,i-delay)]-arr[max(0,i-forget)]+mod)%mod;
    //max (0,i-delay/i-forget) because i-delay or i-forget can give negative values as negative index    doesnt exist so it will take 0 instead at that time
    // on ith day i-delay people will share the secret and on the ith day i-forget people will forget the secret
            
        }
        
        int ans=0;
        
        for(int i=n-forget+1;i<=n;i++)
        {
            ans=(ans+arr[i])%mod;
        }
        return ans;
            
    }
};