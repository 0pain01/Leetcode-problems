class Solution {
public:
    int combinationSum4(vector<int>& nums, int T) {
        vector<unsigned int> dp(T+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= T; i++)
            for (int num : nums)
                if (num <= i) dp[i] += dp[i-num];
        return dp[T];
    }
};