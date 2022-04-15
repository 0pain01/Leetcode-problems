class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL)
            return NULL;
        // If the current node is less than low,
        // then he and his left child nodes are
        // also less than low, we need to cut them off
        if (root->val < low)
            return trimBST(root->right, low, high);
        //Ditto
        if (root->val > high)
            return trimBST(root->left, low, high);
        // The value of the current node is between low and high
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};