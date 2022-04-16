class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        // Because the value of the current node is the current node
        // plus the value of its right child, we need to traverse
        // the right child first
        convertBST(root->right);
        // accumulate
        sum += root->val;
        root->val = sum;
        // Traverse the left subtree
        convertBST(root->left);
        return root;
    }
};