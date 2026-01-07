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
    static final int MOD = 1000000007;
    long totalSum =0;
    long maxVal = 0;

    public long treeSum(TreeNode root){
        if(root==null)return 0;

        return root.val + treeSum(root.left) + treeSum(root.right);
    }

    long dfs(TreeNode root){
        if(root==null) return 0;

        long left = dfs(root.left);
        long right = dfs(root.right);

        long subSum = root.val + left + right;
        long product = subSum*(totalSum-subSum);
        
        maxVal = Math.max(maxVal , product);

        return subSum;

    }

    public int maxProduct(TreeNode root) {
        totalSum = treeSum(root);
        dfs(root);
        return (int)(maxVal % MOD);
    }
}