class Solution {
public: 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 or grid[n-1][n-1]) return -1;
        vector<int> dirX = {1,0,-1,0,-1,-1,1,1};
        vector<int> dirY = {0,1,0,-1,-1,1,-1,1};
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;
        vis.insert({0,0});
        q.push({0,0});
        int level=1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;++i){
                pair<int,int> top = q.front();q.pop();
                if(top.first == n-1 and top.second == n-1){
                    return level;
                }
                for(int j=0;j<8;++j){
                    int nX = top.first+dirX[j];
                    int nY = top.second+dirY[j];
                    if(nX == n-1 and nY == n-1) {
                        return level+1;
                    }
                    if(nX>=0 and nX<n and nY>=0 and nY<n and grid[nX][nY]==0 and vis.find({nX,nY})==vis.end()){
                        q.push({nX,nY});
                        vis.insert({nX,nY});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};