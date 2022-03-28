class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()- 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) 
                return true;
            while(lo < mid && nums[mid] == nums[lo]) 
                ++lo;
            while(mid < hi && nums[mid] == nums[hi]) 
                --hi;
            if(nums[lo] <= nums[mid]) 
            {
                if(nums[mid] < target || nums[lo] > target) 
                    lo = mid + 1;
                else 
                    hi = mid - 1;
            }
            else {
                if(nums[mid] > target || nums[hi] < target) 
                    hi = mid - 1;
                else 
                    lo = mid + 1;
            }
        }
        return false;
    }
};