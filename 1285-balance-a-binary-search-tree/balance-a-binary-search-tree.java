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
    private void dfs(TreeNode root, List<Integer> arr){
        if(root==null)
            return;

        dfs(root.left,arr);
        arr.add(root.val);
        dfs(root.right,arr);
    }

    private TreeNode buildTree(List<Integer> arr, int left, int right){
        if(left > right)
            return null;

        int mid = left+(right-left)/2;

        TreeNode root = new TreeNode(arr.get(mid));

        root.left = buildTree(arr,left,mid-1);
        root.right = buildTree(arr,mid+1,right);

        return root;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> arr = new ArrayList<Integer> ();
        dfs(root,arr);
        int n = arr.size();

        return buildTree(arr,0,n-1);
    }
}