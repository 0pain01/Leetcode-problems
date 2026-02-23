class Solution {

    // Precomputed factorials for 0–9
    int[] fact = {1,1,2,6,24,120,720,5040,40320,362880};
    
    public boolean isDigitorialPermutation(int n) {
        char [] numString = Integer.toString(n).toCharArray();
        Arrays.sort(numString);

        int sum = 0;
        for(int i = 0; i < numString.length; i++){
            sum += fact[numString[i]-'0'];
        }

        char [] permutSumString = Integer.toString(sum).toCharArray();
        Arrays.sort(permutSumString);

        return Arrays.equals(numString, permutSumString);
    }
}