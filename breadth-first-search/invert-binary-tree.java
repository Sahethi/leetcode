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
    public TreeNode invertTree(TreeNode root) {
        // if (root == null) return null;

        // //recursive DFS through call stack
        // TreeNode temp = root.right;
        // root.right = root.left;
        // root.left = temp;

        // invertTree(root.left);
        // invertTree(root.right);

        // return root;

        if(root == null) return null;

        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);

        while(!stack.isEmpty()){
            TreeNode node = stack.pop();
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;

            if(node.left != null){
                stack.push(node.left);
            }

            if(node.right != null){
                stack.push(node.right);
            }
        }
        return root;
    }
}