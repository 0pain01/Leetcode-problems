class Solution {
    public int minimumCost(int[] nums) {
        int a = nums[0];
        int b=Integer.MAX_VALUE,c=Integer.MAX_VALUE;
        int bi=0;

        for(int i=1;i<nums.length;i++){
            if(b>=nums[i]){
                b=nums[i];
                bi=i;
            }
        }

        for(int i=1;i<bi;i++){
            if(c>=nums[i]){
                c=nums[i];
            }
        }

        for(int i=bi+1;i<nums.length;i++){
            if(c>=nums[i]){
                c=nums[i];
            }
        }

    return a+b+c;
    }
}