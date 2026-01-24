class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int maxSum= Integer.MIN_VALUE;
        for(int i=0;i<n/2;i++){
            maxSum = Math.max(nums[i]+nums[n-i-1],maxSum);
        }
        return maxSum;
    }
}



