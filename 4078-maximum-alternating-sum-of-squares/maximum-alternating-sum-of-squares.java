
import java.util.Arrays;

class Solution {
    public long maxAlternatingSum(int[] nums) {

        Integer[] arr = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, (a, b) -> Integer.compare(Math.abs(a), Math.abs(b)));

        int n = nums.length;
        long ans = 0;

        if (n % 2 == 0) {
            for (int i = n - 1; i >= n / 2; i--) {
                ans += (long) arr[i] * arr[i];
                ans -= (long) arr[n - i - 1] * arr[n - i - 1];
            }
        } else {
            for (int i = n - 1; i > n / 2; i--) {
                ans += (long) arr[i] * arr[i];
                ans -= (long) arr[n - i - 1] * arr[n - i - 1];
            }

            ans += (long) arr[n / 2] * arr[n / 2];
        }

        return ans;
    }
}
