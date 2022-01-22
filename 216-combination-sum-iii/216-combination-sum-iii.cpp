class Solution {
public:
    
    void helper(int idx, vector<int>&arr,vector<vector<int>>&res,vector<int>&ans,int sum,int k)
    {
        if(idx>=arr.size())
        {
            if(k==ans.size() && sum==0)
            {
                res.push_back(ans);
            }
            return;
        }
        
        ans.push_back(arr[idx]);
        helper(idx+1,arr,res,ans,sum-arr[idx],k);
        ans.pop_back();
        
        helper(idx+1,arr,res,ans,sum,k);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        helper(0,arr,res,ans,n,k);
        
        return res;
    }
};