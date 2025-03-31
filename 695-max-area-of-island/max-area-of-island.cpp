class Solution {
public:
    int dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
    
    void dfs(int i,int j , vector<vector<int>>& grid,int &ar){
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size()||grid[i][j]==0){
            return ;
        }

        ar+=1;
        grid[i][j]=0;

        for(int k=0;k<4;k++){
            dfs(i+dir[k][0],j+dir[k][1],grid,ar);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ar=0;
                if(grid[i][j]==1){
                    dfs(i,j,grid,ar);
                    ans = max(ans,ar);
                }
            }
        }

        return ans;
    }
};