/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr;
        ListNode* n;
        ListNode* prev;
        curr = node;
        n = node->next;
        while(n != nullptr)
        {
            prev = curr;
            curr->val = n->val;
            curr = curr->next;
            n = n->next;
        }
        prev->next = nullptr;
        
    }
};
