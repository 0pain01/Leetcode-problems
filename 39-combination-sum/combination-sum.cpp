class Solution {
public:
    void solver(int idx, vector<int>& candidates,int target,vector<int>arr,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(arr);
            return;
        }

        if(idx==candidates.size()||target<0)
            return;


        arr.push_back(candidates[idx]);
        solver(idx,candidates,target-candidates[idx],arr,ans);
        arr.pop_back();
        solver(idx+1,candidates,target,arr,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        int t = candidates.size();
        solver(0,candidates,target,arr,ans);
        return ans;
    }
};