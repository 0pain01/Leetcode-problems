class Solution {
public:
    void helper(int idx,int &sum,vector<int> cdt, vector<vector<int>> &res,int target,int n,vector<int>&temp)
    {
        if(idx>=n || sum>=target)
        {
            if(sum==target)
            {
                res.push_back(temp);
            }
            return;
        }
        
        sum+=cdt[idx];
        temp.push_back(cdt[idx]);
        helper(idx,sum,cdt,res,target,n,temp);
        
        sum-=cdt[idx];
        temp.pop_back();
        
        helper(idx+1,sum,cdt,res,target,n,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>temp;
        int n = candidates.size();
        int sum=0;
        helper(0,sum,candidates,res,target,n,temp);
        return res;
    }
};