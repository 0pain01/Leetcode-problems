class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int idx=i+1,jdx=n-1;
            while(idx<jdx){
                int sum = nums[idx]+nums[jdx]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i],nums[idx],nums[jdx]});
                    while (idx < jdx && nums[idx] == nums[idx + 1]) 
                        idx++;
                    while (idx < jdx && nums[jdx] == nums[jdx - 1]) 
                        jdx--;

                    idx++;
                    jdx--;
                }
                else if(sum<0){
                    idx++;
                }
                else
                    jdx--;
                }
            }
        return ans;
    }
};