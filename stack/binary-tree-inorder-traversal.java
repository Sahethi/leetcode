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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        Deque<TreeNode> stack = new LinkedList<>();
        TreeNode node = root;
        while(true){
            if(node != null){
                stack.push(node);
                node = node.left;
            }else{
                if(stack.isEmpty())
                    break;
                node = stack.pop();
                inorder.add(node.val);
                node = node.right;
            }
        }
        return inorder;

        //Morris Algorithm
        // ArrayList<Integer> inorder = new ArrayList<>();
        // TreeNode curr = root;
        // while(curr != null){
        //     if(curr.left == null){
        //         inorder.add(curr.val);
        //         curr = curr.right;
        //     } else {
        //         //for left subtree thats why curr.left
        //         TreeNode prev = curr.left;
        //         while(prev.right != null && prev.right != curr){
        //             //rightmost element
        //             prev = prev.right;
        //         }
        //         if(prev.right == null){
        //             prev.right = curr;
        //             curr = curr.left;
        //         } else {
        //             prev.right = null;
        //             inorder.add(curr.val);
        //             curr = curr.right;
        //         }
        //     }
        // }
        // return inorder;
    }
}