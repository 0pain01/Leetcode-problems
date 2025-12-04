class Solution {

    public int countCollisions(String directions) {
        int collisions = 0;
        int cars = directions.length();
        char[] directionsArray = directions.toCharArray();

        int convoy = 1;
        for(int curr = 0; curr < cars; curr++) {
            char currDir = directionsArray[curr];
            if(currDir == 'S') continue;
            
            int checkingIdx = currDir == 'L' ? curr - 1 : curr + 1;
            if(checkingIdx < 0 || checkingIdx >= cars) continue;

            if(currDir != directionsArray[checkingIdx]) {
                directionsArray[curr] = 'S';
                collisions += convoy;
                convoy = 1;
            } else if(currDir == 'R') {
                convoy++;
            }
        }

        return collisions;
    }
}