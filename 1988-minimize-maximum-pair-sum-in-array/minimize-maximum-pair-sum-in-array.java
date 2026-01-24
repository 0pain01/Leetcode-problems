class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int max =0;
        int start =0;
        int end = nums.length-1;
        while(end>start){
            int temp = nums[start]+nums[end];
            if(temp>max)max=temp;
            start++;
            end--;
        }
        return max;
    }
}



