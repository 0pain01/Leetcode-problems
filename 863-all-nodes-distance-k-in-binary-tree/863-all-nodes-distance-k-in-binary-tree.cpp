class Graph {
  
    unordered_map<TreeNode*, list<TreeNode*> > adjList;
public:
    
    void addEdge(TreeNode* u, TreeNode* v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<int> bfsSSSP(TreeNode* src, int k) {
        unordered_map<TreeNode*, int> distance;
        unordered_map<TreeNode*, bool> visited;
        
        
        queue<TreeNode*> q;
        q.push(src);
        visited[src] = true;
        distance[src] = 0;
        
        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            
            for(auto &i:adjList[f]) {
                if(!visited[i]) {
                    visited[i] = true;
                    distance[i] = distance[f] + 1;
                    q.push(i);
                }
            }
            
        }
        
        vector<int> ans;
        for(auto &i:distance) {
            if(i.second==k){
                ans.push_back(i.first->val);
            }
        }
        
        
        return ans;
        
    }
    
};


class Solution {
public:
    void preOrder(Graph &g, TreeNode* root) {
        if(!root||!root->left and !root->right)
            return;
        
        if(root->left)
            g.addEdge(root,root->left);
        if(root->right)
            g.addEdge(root,root->right);
        
        preOrder(g,root->left);
        preOrder(g,root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        Graph g;
        // addEdge(g,root);
        preOrder(g,root);
        return g.bfsSSSP(target,k);
        
    }
};