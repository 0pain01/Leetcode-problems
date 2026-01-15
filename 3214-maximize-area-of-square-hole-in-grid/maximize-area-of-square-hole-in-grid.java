class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int maxConsecutiveHbars=1;
        int maxConsecutiveVbars=1;

        int currentConsecutiveHBars=1;

        for(int i=1;i<hBars.length;i++){
            if(hBars[i]-hBars[i-1]==1){
                currentConsecutiveHBars++;
            }else{
                currentConsecutiveHBars=1;
            }
            maxConsecutiveHbars=Math.max(currentConsecutiveHBars,maxConsecutiveHbars);
        }

        int currentConsecutiveVBars=1;
        for(int i=1;i<vBars.length;i++){
            if(vBars[i]-vBars[i-1]==1){
                currentConsecutiveVBars++;
            }else{
                currentConsecutiveVBars=1;
            }
            maxConsecutiveVbars=Math.max(currentConsecutiveVBars,maxConsecutiveVbars);
        }

        int side = Math.min(maxConsecutiveHbars,maxConsecutiveVbars)+1;
        return side*side;

    }
}