/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int height(TreeNode root){
        if (root == null) return 0;

        return 1+ Math.max(height(root.left),height(root.right));
    }

    public TreeNode dfs(TreeNode root){
        if(root==null)
            return null;

        int leftH  = height(root.left);
        int rightH = height(root.right); 

        if(leftH > rightH){
            return dfs(root.left);
        }

        if(leftH < rightH){
            return dfs(root.right);
        }
        return root;
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root);
    }
}