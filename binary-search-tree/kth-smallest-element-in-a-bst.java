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
    public int kthSmallest(TreeNode root, int k) {
        // if(root == null) return 0;
        // Deque<TreeNode> stack = new LinkedList<>();
        // TreeNode curr = root;
        // int count = 0;
        // while(true){
        //     if(curr != null){
        //         stack.push(curr);
        //         curr = curr.left;
        //     } else {
        //         if(stack.isEmpty())
        //             break;
        //         curr = stack.pop();
        //         if(++count == k) return curr.val;
        //         curr = curr.right;
        //     }
        // }
        // return Integer.MIN_VALUE;

        //Recursive inorder but takes extra stack space
        int res[] = new int[2];
        traverse(root, k, res);
        return res[0];
    }
    private void traverse(TreeNode root, int k, int[] res){
        if(root == null) return;
        traverse(root.left, k, res);
        res[1]++;
        if(res[1] == k){
            res[0] = root.val;
            return;
        }
        traverse(root.right, k, res);
    }
}