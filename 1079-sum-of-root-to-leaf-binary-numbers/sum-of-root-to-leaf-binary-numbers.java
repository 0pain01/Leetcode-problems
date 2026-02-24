class Solution {
    int result = 0;
    private void DFS(TreeNode root, String binaryString){
        binaryString += (root.val);
        if(root.left == null && root.right == null){          
            result += Integer.parseInt(binaryString, 2);;
            return;
        }

        if(root.left != null)
            DFS(root.left, binaryString);
        if(root.right != null)
            DFS(root.right, binaryString);
    }

    public int sumRootToLeaf(TreeNode root) {

        if(root.left == null && root.right == null)
            return root.val;
            
        DFS(root , "");

        return result;
    }
}