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
    public void reorderList(ListNode head) {    
        ListNode fast = head, slow = head;

        //finding the mid point of the list
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        //reversing the second half
        ListNode head2 = reverseList(slow.next);
        //mid being thelast node it's next is null
        slow.next = null;

        mergeTwoLists(head, head2);
    }

    private ListNode reverseList(ListNode head2){
        ListNode prev = null;
        while(head2 != null){
            ListNode next = head2.next;
            head2.next = prev;
            prev = head2;
            head2 = next;
        }
        return prev;
    }

    private void mergeTwoLists(ListNode head1, ListNode head2){
        while(head1 != null && head2 != null){
            ListNode next1 = head1.next;
            ListNode next2 = head2.next;
            
            head2.next = head1.next;
            head1.next = head2;
            head1 = next1;
            head2 = next2;
        }
    }
}