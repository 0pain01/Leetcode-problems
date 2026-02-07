class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int left = 0;
        int right = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a')
                right++;
        }

        int ans = right; 

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'a') {
                right--;      
            } else {
                left++;     
            }
            ans = Math.min(ans, left + right);
        }

        return ans;
    }
}
