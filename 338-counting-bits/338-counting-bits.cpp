class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        if(n==0)
        {
            res.push_back(0);
            return res;
        }
        
        if(n==1)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        res.push_back(0);
        res.push_back(1);
        
        for(int i=2;i<=n;i++)
        {
            int n = i;
            int count=0;
            while(n!=0)
            {
                if(n&1)
                {
                    count++;
                }
                n=n>>1;
            }
            res.push_back(count);
        }
        
        return res;
    }
};