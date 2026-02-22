class Solution {
    public int binaryGap(int n) {
        int distance = 0;
        int maxDistance = 0;
        boolean flag = false;

        while(n > 0){
            int digit = n & 1;

            if(digit == 1){
                if(!flag){
                    flag = true;
                }
                else{
                    maxDistance = Math.max(maxDistance,distance + 1);
                    distance = 0;
                }
            }
            else{
                if(flag){
                    distance ++;
                }
            }

            n = n >> 1;
        }

        return maxDistance;
    }
}