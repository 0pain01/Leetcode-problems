class Solution {

    public int countCollisions(String directions) {
        
        int n = directions.length();
        int x=0,y=n-1;

        while(x<n  && directions.charAt(x)=='L') x++;

        while(y>=0 && directions.charAt(y)=='R') y--;
        
        int ans=0;
        for(int i=x;i<=y;i++){
            if(directions.charAt(i)!='S')
                ans++;
        }

        return ans;
    }



    /*
    

    public int countCollisions(String directions) {
        int collisions = 0;
        int cars = directions.length();
        boolean prevCollision = false;

        int convoy = 1;
        for(int curr = 0; curr < cars; curr++) {
            char currDir = directions.charAt(curr);
            if(currDir == 'S') continue;
            
            int checkingIdx = currDir == 'L' ? curr - 1 : curr + 1;
            if(checkingIdx < 0 || checkingIdx >= cars) continue;

            if((checkingIdx < curr && prevCollision) || currDir != directions.charAt(checkingIdx)) {
                collisions += convoy;
                prevCollision = true;
                convoy = 1;
            } else if(currDir == 'R') {
                convoy++;
            }
        }

        return collisions;
    }
    
    */
}