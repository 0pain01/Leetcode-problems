class Solution {
    public int numSpecial(int[][] mat) {
        int n = mat.length;
        int [] row = new int [mat.length];
        int [] col = new int [mat[0].length];

        for(int i = 0 ; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }

        System.out.println("row:");
        for(int i = 0 ; i < mat.length; i++)
            System.out.println(row[i]);
        
        System.out.println("col:");
        for(int i = 0 ; i < mat[0].length; i++)
            System.out.println(col[i]);

        int ans = 0;

        for(int i = 0 ; i < mat.length; i++){
            for(int j = 0; j < mat[0].length; j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1)
                    ans += 1;
            }
        }
        return ans;

    }
}