class Solution {
public:
    void solver(int idx, vector<int>&nums,vector<int>arr,vector<vector<int>>&ans){
        if(idx>=nums.size())
        {
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[idx]);
        solver(idx+1,nums,arr,ans);
        arr.pop_back();
        solver(idx+1,nums,arr,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>arr;
        solver(0,nums,arr,ans); 
        return ans;
    }
};