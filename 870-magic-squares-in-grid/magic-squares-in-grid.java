class Solution {
    public boolean checker(int[][] grid, int i, int j ){
        int sum =0;
        sum = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        boolean[] seen = new boolean[10];
        // row-wise
        for(int x=i;x<i+3;x++){
            int chck=0;
            for(int y=j;y<j+3;y++){
                if(grid[x][y]<1 || grid[x][y]>9 || seen[grid[x][y]])
                    {return false;}
                seen[grid[x][y]]=true;
                chck+=grid[x][y];
            }
            if(chck!=sum)
                {return false;}
        }

        // column-wise
        for(int y=j;y<j+3;y++){
            int chck=0;
            for(int x=i;x<i+3;x++){
                chck+=grid[x][y];
            }
            if(chck!=sum)
                {return false;}
        }

        // diagonal 1
        if(sum != (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]))
            {return false;}

        // diagonal 2
        if(sum != (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]))
            {return false;}
        
        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(checker(grid,i,j))
                    cnt++;
            }
        }

        return cnt;
    }
}