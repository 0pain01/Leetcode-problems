class Solution {
    public int findMin(int[] nums) {
        int i = 0 , j = nums.length - 1;
        int a = 0, b = 0;
        while(i < j){
            if(nums[i] > nums[j]){
                i++;
            }
            else if(nums[j] > nums[i]){
                j--;
            }
        }

        return Math.min(nums[i],nums[j]);
    }
}