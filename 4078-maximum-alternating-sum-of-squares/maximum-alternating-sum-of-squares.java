
class Solution {

    public long maxAlternatingSum(int[] nums) {
        sortByAbs(nums, 0, nums.length - 1);

        int left = 0;
        int right = nums.length - 1;
        long ans = 0;

        while (left < right) {
            ans += (long) nums[right] * nums[right];
            ans -= (long) nums[left] * nums[left];

            left++;
            right--;
        }

        if (left == right) {
            ans += (long) nums[left] * nums[left];
        }

        return ans;
    }

    private void sortByAbs(int[] nums, int low, int high) {
        if (low >= high) return;

        int i = low;
        int j = high;
        long pivot = Math.abs((long) nums[low + (high - low) / 2]);

        while (i <= j) {
            while (Math.abs((long) nums[i]) < pivot) i++;
            while (Math.abs((long) nums[j]) > pivot) j--;

            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }

        if (low < j) sortByAbs(nums, low, j);
        if (i < high) sortByAbs(nums, i, high);
    }
}
