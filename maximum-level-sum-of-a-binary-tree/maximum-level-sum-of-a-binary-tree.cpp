/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        int sum=0,maxsum=INT_MIN,cntmax=0;
        
        queue <TreeNode*> q;
        if(root==NULL)
            return 0;
        
       
        
        q.push(root);
        q.push(NULL);
        sum=root->val;
        int cnt=1;
        while(!q.empty())
        {
            root=q.front();
            
            q.pop();
            if(root!=NULL)
            {
                cout << root->val << endl;
                sum=sum+root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            else
            {
                cout<<sum<<" ";
                
                if(maxsum<sum)
                {
                    maxsum=sum;
                    cntmax=cnt;
                }
                cnt++;
                sum=0;
                 if(!q.empty())
                 {
                     q.push(NULL);
                 }
                
            }
        }
        
        return cntmax;
    }
};