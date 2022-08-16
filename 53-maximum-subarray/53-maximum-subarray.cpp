class Solution {
public:
    void solve(vector<int>& nums,int i,int sum,int &maxi)
    {
        if(i==nums.size())
        {
            // maxi=max(sum,maxi);
            return;
        }
        sum=sum+nums[i];
        if(nums[i]>sum)
        {
            sum=nums[i];
        }
        maxi=max(sum,maxi);
        solve(nums,i+1,sum,maxi);
    }
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        solve(nums,0,0,maxi);
        return maxi;
        // vector<int>dp=nums;
        // for(int i=1;i<nums.size();i++)
        // {
        //     dp[i]=max(dp[i],dp[i]+dp[i-1]);
        //     dp[0]=max(dp[0],dp[i]);
        // }
        // return dp[0];
        
    }
};