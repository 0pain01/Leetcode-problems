class Solution {
public:
    
    void helper(int idx, vector<int>nums,vector<vector<int>>&res,vector<int>&ans)
    {
         res.push_back(ans);
        for(int i=idx;i<nums.size();i++)
        {
            if(i!=idx && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            helper(i+1,nums,res,ans);
            ans.pop_back();
            
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        helper(0,nums,res,ans);
        return res;
    }
};