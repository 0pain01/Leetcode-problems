class Solution {
public:
    void dfs(int i , int n , vector<vector<int>>& isConnected,vector<bool>& vis){
        vis[i]=true;
        isConnected[i][i]=0;

        for(int j=0;j<n;j++){
            if(!vis[j] && isConnected[i][j]==1){
                isConnected[i][j]=0;
                dfs(j,n,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,0);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,n,isConnected,vis);
            }
        }

        return cnt;
    }
};