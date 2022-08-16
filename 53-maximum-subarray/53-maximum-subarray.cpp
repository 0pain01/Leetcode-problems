class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp=nums;
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(dp[i],dp[i]+dp[i-1]);
            dp[0]=max(dp[0],dp[i]);
        }
        return dp[0];
        
    }
};