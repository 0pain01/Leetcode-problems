class Solution {
public:
    void helper(int idx,vector<int>&nums,set<vector<int>>&res)
    {
        if(idx==nums.size())
        {
            res.insert(nums);
            return;
        }
        
        for(int j = idx;j<nums.size();j++)
        {   
                swap(nums[j],nums[idx]);
                helper(idx+1,nums,res);
                swap(nums[idx],nums[j]);        
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ans;
        
        helper(0,nums,res);
        
        for(auto x: res)
        {
            ans.push_back(x);
        }
        
        return ans;
    }
};