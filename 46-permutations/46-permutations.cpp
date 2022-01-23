class Solution {
public:
    
    void helper(vector<int>nums,vector<vector<int>>&res,vector<int>&ans,vector<bool> &vis)
    {
        if(ans.size()==nums.size())
        {
            res.push_back(ans);
            return;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            if(vis[i]==false)
            {
                ans.push_back(nums[i]);
                vis[i]=true;
                helper(nums,res,ans,vis);
                ans.pop_back();
                vis[i]=false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>ans;
        vector<bool> vis(nums.size(),false);
        helper(nums,res,ans,vis);
        
        return res;
    }
};