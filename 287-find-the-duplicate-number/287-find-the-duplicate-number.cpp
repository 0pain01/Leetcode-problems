class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int res = -1;
        for(int i = 0; i < nums.size(); ++i) 
        {
            int idx = abs(nums[i]);
            if(nums[idx] < 0) 
            {
                res = idx;
                break;
            }
            nums[idx] *= -1;
        }
        
        return res;
    }
};