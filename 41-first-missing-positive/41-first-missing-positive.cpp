class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s;
        for(auto it:nums)
        {
            s.insert(it);
        }
        
        int i=1;
        for(auto it:s)
        {
            if(it==i)
            {
                i++;
            }
            else if(it>i)
            {
                break;
            }
        }
        return i;
    }
};