class Solution {
public:
    vector<bool>vis;
    vector<int>color;
    bool bfs(int i,vector<vector<int>>& graph){
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            vis[top]=true;

            for(auto it: graph[top]){
                if(!vis[it]){
                    if(color[it]==-1){
                        if(color[top]==0)
                            color[it]=1;
                        else
                            color[it]=0;
                        q.push(it);
                    }
                    else{
                        if(color[top]==color[it])
                            return false;
                        else
                            q.push(it);
                    }    
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n,false);
        color.resize(n,-1);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!bfs(i,graph))
                    return false;
            }
        }
        return true;  
    }
};