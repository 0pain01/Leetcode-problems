class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int cnt = 0;
        int n = nums.length;
        int [] ans = new int[n];

        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == pivot)
                cnt++;
            if(nums[i] < pivot){
                ans[j] = nums[i];
                j++;
            }
        }

        for(int i = 0; i < cnt; i++){
            ans[j] = pivot;
            j++;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > pivot){
                ans[j] = nums[i];
                j++;
            }
        }

        return ans;
    }
}

