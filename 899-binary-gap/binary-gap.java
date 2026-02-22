class Solution {
    public int binaryGap(int n) {
        int distance = 0;
        int maxDistance = 0;
        boolean flag = false;

        while(n > 0){
            int digit = n & 1;
            System.out.println(digit);
            if(digit == 1 && flag == false){
                flag = true;
            }
            else if(digit == 1 && flag == true){
                maxDistance = Math.max(maxDistance,distance + 1);
                distance = 0;
            }
            
            if(digit == 0 && flag == true){
                distance++;
            }

            n = n >> 1;
        }

        return maxDistance;
    }
}