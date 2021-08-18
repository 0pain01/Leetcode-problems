class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret; 
        
        for(int i = 0; i <= n-3 && nums[i] <= 0; i++) {
            if (i!=0 && nums[i-1] == nums[i]) 
                continue;
            
            int target = -1*nums[i];
            
            int l = i+1, h = n-1;
            
            while( l < h ) {
                int curSum = nums[l]+nums[h];
                if (curSum > target) {
                    h--;
                } else if (curSum < target) {
                    l++;
                } else {
                    ret.push_back({nums[i], nums[l], nums[h]});
                    while(l < h && nums[l] == nums[l+1]) l++;
                    while(l < h && nums[h] == nums[h-1]) h--;
                    l++, h--;
                }
            }
        }
        
        return ret;
    }
};