class Solution {
public:
    void helper(int idx,vector<int> cdt, vector<vector<int>> &res,int target,int n,vector<int>&temp)
    {
        if(idx>=n)
        {
            if(target==0)
            {
                res.push_back(temp);
            }
            return;
        }
        
        if(cdt[idx]<=target)
        {
            temp.push_back(cdt[idx]);
            helper(idx,cdt,res,target-cdt[idx],n,temp);
            temp.pop_back();
        }
        
        helper(idx+1,cdt,res,target,n,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>temp;
        int n = candidates.size();
        helper(0,candidates,res,target,n,temp);
        return res;
    }
};