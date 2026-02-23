class Solution {
    
    public boolean isDigitorialPermutation(int n) {
        int n1 = n;
        int maxDigit = 0;
        char [] numString = Integer.toString(n).toCharArray();
        Arrays.sort(numString);

        while(n1 > 0){
            maxDigit = Math.max(maxDigit, n1 % 10);
            n1 = n1 / 10;
        }

        int [] permut = new int [maxDigit+1];
        permut [0] = 1;
        permut [1] = 1;

        for(int i=2 ; i <= maxDigit; i++){
            permut[i] = permut[i-1] * i;
        }

        int sum = 0;
        for(int i = 0; i < numString.length; i++){
            sum += permut[numString[i]-'0'];
        }

        char [] permutSumString = Integer.toString(sum).toCharArray();
        Arrays.sort(permutSumString);

        

        return Arrays.equals(numString, permutSumString);
    }
}