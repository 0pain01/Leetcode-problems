class Solution {
    private int[][] solver(int [][] matrix, int idx, int jdx){
        for(int i = 0; i < matrix[0].length; i++){
            matrix[idx][i] = 0;
        }

        for(int i = 0; i < matrix.length; i++){
            matrix[i][jdx] = 0;
        }

        return matrix;
    }

    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        boolean [][] posZero = new boolean[n][m];

        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    posZero[i][j] = true;
                }
                else
                    posZero[i][j] = false;
            }
        } 

        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++){
                if(posZero[i][j]==true){
                    matrix = solver(matrix,i,j);
                }
            }
        }  
    }
}