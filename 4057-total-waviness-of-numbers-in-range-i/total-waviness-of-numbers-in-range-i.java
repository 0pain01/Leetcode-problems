class Solution {
    public int totalWaviness(int num1, int num2) {
        int count = 0;

        for (int i = num1; i <= num2; i++) {
            count += waveCounter(String.valueOf(i));
        }

        return count;
    }

    private int waveCounter(String s) {
        int cnt = 0;

        for (int i = 1; i < s.length() - 1; i++) {
            int prev = s.charAt(i - 1) - '0';
            int curr = s.charAt(i) - '0';
            int next = s.charAt(i + 1) - '0';

            if ((curr > prev && curr > next) ||
                (curr < prev && curr < next)) {
                cnt++;
            }
        }

        return cnt;
    }
}