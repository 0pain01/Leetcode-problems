class Solution {
    public int countPartitions(int[] nums) {
        int n = nums.length;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int counter=0;
        int sum1=0;
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];
            sum-=nums[i];
            if((sum1-sum)%2==0)
                counter++;
        }
        return counter;
    }
}