/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        //basically we are mapping which original node is mapped to the copy
        Node* curr = head;

        while(curr != NULL){
            Node* copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL){
            if(curr->next != NULL) mp[curr]->next = mp[curr->next];
            else mp[curr]->next = NULL;

            if(curr->random != NULL) mp[curr]->random = mp[curr->random];
            else mp[curr]->random = NULL;

            curr = curr->next;
        }

        if(head == NULL) return NULL;
        return mp[head];
    }
};