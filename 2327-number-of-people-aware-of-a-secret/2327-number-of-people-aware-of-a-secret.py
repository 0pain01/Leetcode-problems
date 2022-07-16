class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        arr=[1]+[0]*(n-1)
        mod=10**9+7;
        p=0
        for i in range(1,n):
            arr[i]=p=(p+arr[i-delay]-arr[i-forget])%mod
        
        ans=0
        for i in range(n-forget,n):
            ans=(ans+arr[i])%mod
        
        return ans
        
        