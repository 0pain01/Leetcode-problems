class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int r,int c,vector<vector<bool>>&ocn,vector<vector<int>>& heights){
        ocn[r][c]=true;

        for(int i=0;i<4;i++){
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            if(nr>=0 && nc>=0 && nr<ocn.size() && nc<ocn[0].size() && !ocn[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,ocn,heights);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));

        for(int i=0;i<m;i++){
            dfs(0,i,pac,heights);
            dfs(n-1,i,atl,heights);
        }

        for(int i=0;i<n;i++){
            dfs(i,0,pac,heights);
            dfs(i,m-1,atl,heights);
        }

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]&&atl[i][j]){
                    ans.push_back({i,j});
                }   
            }
        }
    return ans;
    }
};