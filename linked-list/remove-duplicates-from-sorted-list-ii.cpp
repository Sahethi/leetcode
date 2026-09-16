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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev;
        ListNode* curr;
        ListNode* dummy = new ListNode(0);

        dummy->next = head;
        curr = head;
        prev = dummy;

        while(curr != NULL){
            if(curr->next != NULL && curr->val == curr->next->val){
                int dupVal = curr->val;

                while (curr != NULL && curr->val == dupVal) {
                    curr = curr->next;
                }

                prev->next = curr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;

    }
};