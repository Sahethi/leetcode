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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        //declaring a temporary head to start
        ListNode head = new ListNode(-1); 
        //current pointer
        ListNode current = head;
        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                current.next = list1;
                list1 = list1.next;
            } else {
                current.next = list2;
                list2 = list2.next;
            } 
            current = current.next;
        }
        current.next = list1 != null ? list1 : list2;
        return head.next;

    //     /** Recursive Solution */
    //     if(list1 == null)
    //         return list2;
    //     if(list2 == null)
    //         return list1;
        
    //     if(list1.val < list2.val){
    //         //as list2 is bigger u dont need to move it
    //         list1.next = mergeTwoLists(list1.next, list2); 
    //         return list1;
    //     } else {
    //         list2.next = mergeTwoLists(list1, list2.next);
    //         return list2;
    //     }
    }
}