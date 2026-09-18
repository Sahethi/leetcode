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
private:
    ListNode* merge(ListNode* left, ListNode* right, ListNode* tail){
        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
    
        //one of the groups will have some more nodes left
        tail->next = (left == NULL) ? right : left;

        while(tail->next != NULL){
            tail = tail->next;
        }

        return tail;
    }

    ListNode* split(ListNode* head, int size){
        if(head == NULL) return NULL;

        ListNode* curr = head;

        for(int i=1; i<size && curr->next != NULL; i++){
            curr = curr->next;
        }

        ListNode* nextGroup = curr->next;
        curr->next = NULL;

        return nextGroup;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int len = 0;
        ListNode* curr = head;

        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        //merge groups of 1 then 2 then 4 then 8

        for(int size = 1; size < len; size *= 2){
            curr = dummy.next;
            ListNode* tail = &dummy;

            while(curr != NULL){
                ListNode* left = curr;
                ListNode* right = split(left, size);

                curr = split(right, size);

                tail = merge(left, right, tail);
            }
        }

        return dummy.next;
    }
};