class Solution {
    public int totalWaviness(int num1, int num2) {
        int count = 0;

        for(int i = num1; i <= num2; i++){
            String str = String.valueOf(i);
            count += waveCounter(str);
        }

        return count;
    }

    private int waveCounter(String s){
        int cnt = 0;

        if(s.length() < 3)
            return 0;

        for(int i = 1; i < s.length() - 1; i++){
            if((s.charAt(i) - '0' > s.charAt(i - 1) - '0') && (s.charAt(i) - '0' > s.charAt(i + 1) - '0')){
                cnt++;
            }
            else if((s.charAt(i) - '0' < s.charAt(i - 1) - '0') && (s.charAt(i) - '0' < s.charAt(i + 1) - '0')){
                cnt++;
            }
        }

        return cnt;
    }
}