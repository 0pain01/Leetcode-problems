class Solution {
    public boolean stoneGame(int[] piles) {
        int alice = 0 , bob = 0;
        int i = 0;
        int j = piles.length-1;

        int counter = 0;
        while(i < j){
            if(counter % 2 == 0){
                if(piles[i] >= piles[j]){
                    alice += piles[i];
                    i++;
                }
                else{
                    alice += piles[j];
                    j--;
                }
            }
            else{
                if(piles[i] >= piles[j]){
                    bob += piles[i];
                    i++;
                }
                else{
                    bob += piles[j];
                    j--;
                }
            }
        }


        return alice > bob ? true :false;
    }
}