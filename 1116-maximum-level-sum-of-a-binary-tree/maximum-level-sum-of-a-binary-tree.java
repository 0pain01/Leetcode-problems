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
   
    public int maxLevelSum(TreeNode root) {
        
        if(root==null)
            return 0;

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int maxSum=Integer.MIN_VALUE;
        int level=0;
        int ans=0;
        while(!q.isEmpty()){
            int size = q.size();
            int currSum=0;
            level++;
            for(int i=0;i<size;i++){
                TreeNode node = q.poll();
                
                currSum+= node.val;
                if(node.left!=null){
                    q.add(node.left);
                }
                if(node.right!=null){
                    q.add(node.right);
                }
            }
            if(currSum>maxSum){
                maxSum=currSum;
                ans=level;
            }
        }
        return ans;
    }
}