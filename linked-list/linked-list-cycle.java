/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        ListNode fast = head, slow = head;

        while(fast.next != null && fast.next.next !=null){
            slow = slow.next; //taking 1 step
            fast = fast.next.next; //talking 2 steps
            if(slow == fast) return true; //if fast and slow pointer meet then there is a cycle
        }
        return false;
    }
}