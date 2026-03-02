class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] rightMost = new int[n];

        for (int i = 0; i < n; i++) {
            int index = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    index = j;
                }
            }
            rightMost[i] = index;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {

            int j = i;
            
            while (j < n && rightMost[j] > i) {
                j++;
            }

            if (j == n) {
                return -1;
            }

            while (j > i) {
                int temp = rightMost[j];
                rightMost[j] = rightMost[j - 1];
                rightMost[j - 1] = temp;
                swaps++;
                j--;
            }
        }

        return swaps;
    }
}