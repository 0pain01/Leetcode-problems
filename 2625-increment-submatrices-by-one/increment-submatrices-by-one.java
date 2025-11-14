class Solution {

    public void func(int i, int j, int k, int l, int [][] arr){
         for(int x=i;x<=k;x++){
            for(int y=j;y<=l;y++){
                arr[x][y]++;
            }
         }   
    }
    public int[][] rangeAddQueries(int n, int[][] queries) {
        
        int [][] arr = new int[n][n];

        for(int i=0;i<queries.length;i++){
            func(queries[i][0],queries[i][1],queries[i][2],queries[i][3], arr);
        }
        return arr;
    }
}