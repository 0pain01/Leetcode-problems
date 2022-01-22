class Solution {
public:
    
    void helper(int i, vector<int>nums,vector<vector<int>>&res,vector<int>&ans)
    {
        if(i>=nums.size())
        {
            res.push_back(ans);
            return;
        }
        
        helper(i+1,nums,res,ans);
        ans.push_back(nums[i]);
        helper(i+1,nums,res,ans);
        ans.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>ans;
        
        helper(0,nums,res,ans);
        return res;
    }
};