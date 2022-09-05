/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>ans;
        vector<int> k;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            auto x= q.front();
            q.pop();
            if(x!=NULL)
            {
                k.push_back(x->val);
                vector<Node*>tmp=x->children;
                for(auto it:tmp)
                    q.push(it);
            }
            else if(!q.empty())
            {
                q.push(NULL);
                ans.push_back(k);
                k.clear();
            }          
        }
        ans.push_back(k);
        return ans;     
    }
};