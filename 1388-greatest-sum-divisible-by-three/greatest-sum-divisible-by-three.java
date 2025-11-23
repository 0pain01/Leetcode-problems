class Solution {

    public int maxSumDivThree(int[] nums) {
        int[] dp = new int[3];
        dp[0] = 0;
        dp[1] = Integer.MIN_VALUE;
        dp[2] = Integer.MIN_VALUE;
        
        for (int x : nums) {
            int [] temp = dp.clone();
            for (int r = 0; r < 3; r++) {
                if(temp[r]!=Integer.MIN_VALUE){
                    int newR = (r + x % 3) % 3;
                    dp[newR] = Math.max(dp[newR], temp[r] + x);
                }
                
            }
        }
        
        return dp[0];

    }
}