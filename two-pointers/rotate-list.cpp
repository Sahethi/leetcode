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
    ListNode* rotateRight(ListNode* head, int k) {
        // no. of rotations would be like 
        // k = k % n
        if(head == NULL || head->next == NULL) return head;

        int n = 0;
        ListNode* curr;
        curr = head;
        
        while(curr != NULL){
            n++;
            curr = curr->next;
        }

        k = k % n;
        if(k==0) return head;

        int pos = n - k;
        ListNode* newHead;
        curr = head;
        int c = 0;
        while(curr != NULL){
            c++;
            if(c == pos) break;
            curr = curr->next;
        }

        newHead = curr->next;
        curr->next = NULL;

        curr = newHead;

        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = head;

        return newHead;

    }
};