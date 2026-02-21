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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> postOrder = new LinkedList<>();
        if(root == null)
            return postOrder;
        Deque<TreeNode> st1 = new LinkedList<>();
        st1.push(root);
        while(!st1.isEmpty()){
            TreeNode node = st1.pop();
            postOrder.addFirst(node.val);
            if(node.left != null) st1.push(node.left); 
            if(node.right != null) st1.push(node.right); 
        }
        return postOrder;


        // List<Integer> postOrder = new ArrayList<>();
        // if(root == null)
        //     return postOrder;
        // Deque<TreeNode> st1 = new LinkedList<>();
        // Deque<TreeNode> st2 = new LinkedList<>();
        
        // st1.push(root);
        // while(!st1.isEmpty()){
        //     root = st1.pop();
        //     st2.push(root);
        //     if(root.left != null) st1.push(root.left);
        //     if(root.right != null) st1.push(root.right);
        // }
        // while(!st2.isEmpty()){
        //     postOrder.add(st2.pop().val);
        // }
        // return postOrder;
    }
}