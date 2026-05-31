class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        int n = asteroids.length;
        long pre [] = new long [n+1];

        if(asteroids[0] <= mass)
            pre[0] = mass + asteroids[0];
        else
            return false;

        for(int i = 1; i < n; i++){
            if(asteroids[i] <= pre[i-1]){
                pre[i] = pre[i-1] + asteroids[i];
            }
            else
                return false;
        }

        return true;
    }
}