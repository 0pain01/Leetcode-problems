class Solution {
    public int scoreDifference(int[] nums) {
        int player1 = 0;
        int player2 = 0;

        boolean reverse = false;

        for(int i = 0; i < nums.length; i++){
            if((nums[i] % 2 != 0)){
                if(!reverse){
                    reverse = true;
                }
                else{
                    reverse = false;
                }
            }
            if((i + 1) % 6 == 0){
                if(!reverse){
                    reverse = true;
                }
                else{
                    reverse = false;
                }
            }
            if(!reverse){
                player1 += nums[i];
            }
            else{
                player2 += nums[i];
            }
        }
        
        return player1 - player2;
    }
}