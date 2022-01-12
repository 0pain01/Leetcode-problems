class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            int n = i;
            while(n!=0)
            {
                if(n&1)
                {
                    res[i]++;
                }
                n=n>>1;
            }
        }
        
        return res;
    }
};