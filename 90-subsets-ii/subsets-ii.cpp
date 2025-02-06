class Solution {
public:
    void solver(int idx, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans){
        ans.push_back(arr);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) 
                continue;  

            arr.push_back(nums[i]);
            solver(i + 1, nums, arr, ans);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        sort(nums.begin(),nums.end());
        solver(0,nums,arr,ans);
        return ans;
    }
};