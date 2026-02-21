/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head, slow = head;
        for(int i=0; i<n; i++)
            fast = fast.next;
        // in the case n is equal to the end of the list, 
        // return from 2nd element of LL
        if (fast == null) return head.next;
        //because we need stop one node earlier than the target node
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }   
        //slow stops 1 before the target node
        slow.next = slow.next.next;
        return head;
    }
}