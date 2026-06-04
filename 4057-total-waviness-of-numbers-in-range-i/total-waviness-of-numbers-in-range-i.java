class Solution {
    public int totalWaviness(int num1, int num2) {
        int count = 0;

        for (int i = num1; i <= num2; i++) {
            count += waveCounter(i);
        }

        return count;
    }

    private int waveCounter(int n) {
        if (n < 100) {
            return 0;
        }

        int[] digits = new int[10]; 
        int len = 0;

        while (n > 0) {
            digits[len++] = n % 10;
            n /= 10;
        }

        int cnt = 0;

        for (int i = len - 2; i >= 1; i--) {
            int prev = digits[i + 1];
            int curr = digits[i];
            int next = digits[i - 1];

            if ((curr > prev && curr > next) ||
                (curr < prev && curr < next)) {
                cnt++;
            }
        }

        return cnt;
    }
}