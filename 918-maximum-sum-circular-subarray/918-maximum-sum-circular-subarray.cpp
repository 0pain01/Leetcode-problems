class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
                sum+=nums[i];
        
        vector<int>dp=nums;
        vector<int>dp1=nums;
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(dp[i],dp[i]+dp[i-1]);
            dp[0]=max(dp[0],dp[i]);
        }
        
        for(int i=1;i<nums.size();i++)
        {
            dp1[i]=min(dp1[i],dp1[i]+dp1[i-1]);
            dp1[0]=min(dp1[0],dp1[i]);
        }
        cout<<dp1[0];
        
        return max(dp[0],(dp1[0]==sum) ?sum : sum-dp1[0]);
         
    }
};