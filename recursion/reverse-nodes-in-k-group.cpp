/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupStart = head;
        ListNode* checker = groupStart;
        ListNode* prevGroupTail = dummy;

        while(true){
            int count = 0;
            while(count < k && checker!=NULL){
                checker = checker->next;
                count++;
            }
            if(count <k) break;

            //reversing
            ListNode* prev = checker;
            ListNode* curr = groupStart;
            while(curr != checker){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            prevGroupTail->next = prev;
            prevGroupTail = groupStart;
            groupStart = checker;
        }
        return dummy->next;
    
    }
};