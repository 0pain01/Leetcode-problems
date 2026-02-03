class Solution {
    public boolean isTrionic(int[] nums) {
        boolean a=false,b=false,c=false;
        int ai=0,bi=0,ci=0;

        for(int i=1;i<nums.length;i++){
            if(nums[i]>nums[i-1]){
                a=true;
                ai=i;
            }
            else 
                break;
        }

        for(int i=ai+1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                b=true;
                bi=i;
            }
            else
                break;
        }

        for(int i=bi+1;i<nums.length;i++){
            if(nums[i]>nums[i-1]){
                if(i==nums.length-1)
                    c=true;
            }
            else
                break;
        }

    return (a&b&c);
    }
}