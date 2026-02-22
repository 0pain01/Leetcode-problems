class Solution {
    public int binaryGap(int n) {
        int distance = 0;
        int maxDistance = 0;
        boolean flag = false;

        while(n > 0){
            int digit = n & 1;

            if(digit == 1){
                // starting the distance maping
                if(!flag){
                    flag = true;
                }
                // ending the distance maping with including the last 1
                else{
                    maxDistance = Math.max(maxDistance,distance + 1);
                    // reseting for the next 1-1 mapping
                    distance = 0;
                }
            }
            else{
                // if the distance mapping is on then counting the distance
                if(flag){
                    distance ++;
                }
            }

            // removing last digit with right shift
            n = n >> 1;
        }

        return maxDistance;
    }
}