class Solution {
    public int repeatedNTimes(int[] nums) {
        int []arr = new int[10001];
        int mx =0;
        for(int i=0;i<nums.length;i++){
            arr[nums[i]]+=1;
            if(mx<nums[i])
                mx=nums[i];
        }

        for(int i=0;i<=mx;i++){
            if(2*arr[i]==nums.length)
                return i;
        }

    return 0;  
    }
}