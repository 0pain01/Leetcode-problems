class Solution {
public:
    void solver(int idx, vector<int>&nums,set<vector<int>>&s,vector<int>arr){
        if(idx>=nums.size()){
            sort(arr.begin(),arr.end());
            s.insert(arr);
            return;
        }

        arr.push_back(nums[idx]);
        solver(idx+1,nums,s,arr);
        arr.pop_back();
        solver(idx+1,nums,s,arr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>arr;
        solver(0,nums,s,arr);
        vector<vector<int>>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};