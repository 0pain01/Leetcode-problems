class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int max_altitude = 0;
        if (gain[0] > 0)
            max_altitude = gain[0];

        int prev_height = gain[0];
        
        for(int i = 1; i < n; i++){
            if(max_altitude < (prev_height + gain[i])){
                max_altitude = prev_height + gain[i];
            }

            prev_height = (prev_height + gain[i]);
        }

        return max_altitude;
    }
}