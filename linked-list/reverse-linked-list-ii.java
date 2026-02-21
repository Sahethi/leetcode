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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;

        //start from actual head we need two pointed to be placed prev and curr 
        // before and on left
        for(int i = 1; i < left; i++){
            prev = prev.next;
        }
        
        ListNode leftLink = prev.next;
        ListNode curr = prev.next;
        ListNode previous = prev;

        for(int i=left; i<=right; i++){
            ListNode next = curr.next;
            curr.next = previous;
            previous = curr;
            curr = next;
        }
        
    
        prev.next = previous;
        //2 -> 5
        leftLink.next = curr;

        return dummy.next;
        
        

        // ListNode dummy = new ListNode(-1);
        // dummy.next = head;
        // ListNode prev = dummy;

        // for(int i=1; i<left; i++){
        //     prev = prev.next;
        // }

        // ListNode leftLink = prev.next;
        // ListNode curr = prev.next;
        // ListNode previous = prev;

        // //reversing
        // for(int i=left; i<=right; i++){
        //     ListNode next = curr.next;
        //     curr.next = previous;
        //     previous = curr;
        //     curr = next;
        // }

        // //linking
        // prev.next = previous;
        // leftLink.next = curr;

        // return dummy.next;
    }
}