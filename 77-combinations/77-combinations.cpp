class Solution {
public:
    void helper(int beg, int n ,int k, vector<vector<int>>&res,vector<int>&ans)
    {
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        
        for(int i=beg;i<=n;i++){
            ans.push_back(i);
            helper(i+1,n,k,res,ans);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int>ans;
        helper(1,n,k,res,ans);
        return res;
    }
};