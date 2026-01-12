class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int distance =0;
        int n= points.length;

        for(int i=0;i<n-1;i++){
            distance+= Math.max(Math.abs(points[i+1][0]-points[i][0]),Math.abs(points[i+1][1]-points[i][1]));
        }

        return distance;
    }
}

