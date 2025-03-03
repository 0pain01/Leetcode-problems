class Solution {
public:
void solver(int idx, vector<int>& candidates,int target,vector<int>arr,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(arr);
            return;
        }

        if(target<0 )
            return;

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            arr.push_back(candidates[i]);
            solver(i+1,candidates,target-candidates[i],arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>arr;
        sort(candidates.begin(),candidates.end());
        int t = candidates.size();
        solver(0,candidates,target,arr,ans);
        return ans;
    }
};