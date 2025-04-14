class Solution {
public:
    vector<int>color;
    bool dfs(int i,int paint, vector<vector<int>>& graph){
        if(color[i]==paint){
            return false;
        }
        color[i]=paint;

        for(auto it: graph[i]){
            if(color[it]==paint){
                return false;
            }
            if(color[it]==-1){
                if(paint==0){
                    if(!dfs(it,1,graph))
                        return false;
                }
                else{
                    if(!dfs(it,0,graph))
                        return false;
                }
            }
        }
        return true;        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,graph))
                    return false;
            }
        }
        return true;  
    }
};