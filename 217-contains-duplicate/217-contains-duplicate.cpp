class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        set <int> s;
        s.insert(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
            }
            else
                return true;
        }
        
        return false;
        
    }
};