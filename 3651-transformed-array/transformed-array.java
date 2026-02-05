class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int [] ans = new int [n];

        for(int i=0;i<n;i++){
            int idx=i;
            if(nums[i]>0){
                idx = (i+nums[i])%n;
            }
            else if(nums[i]<0){
                int d = (Math.abs(nums[i]))%n;
                idx = (i-d+n)%n;
            }
            ans[i]=nums[idx];
        }
        return ans;
    }
}