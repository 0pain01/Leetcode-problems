class Solution {
public:
    int countHousePlacements(int n) {
        vector<long>res(n);
        int mod = 1e9+7;
        res[0]=2;
        if(n>1)
            res[1]=3;
        
        for(int i=2;i<n;i++)
        {
            res[i]=(res[i-1]+res[i-2])%mod;
        }
        int ans = (res[n-1]*res[n-1])%mod;
        
        return ans;
        
    }
};