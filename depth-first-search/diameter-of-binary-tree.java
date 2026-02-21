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
    public int diameterOfBinaryTree(TreeNode root) {
        //because arrays are call by reference, u can use this instead of a global variable
        int max[] = new int[1];
        maxDepth(root, max);
        return max[0];
    }
    private int maxDepth(TreeNode root, int[] max){
        if(root == null)
            return 0;
        int left = maxDepth(root.left, max);
        int right = maxDepth(root.right, max);

        max[0] = Math.max(left+right, max[0]);

        return 1 + Math.max(left,right);
    }
}