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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)return head;
        if(head->next == nullptr)return head;

        ListNode* root=head->next;
        ListNode* temp=nullptr;
        ListNode* t1 = head;
        ListNode* t2 = head->next;

        while (t1 != nullptr && t2 != nullptr)
        {
            t1->next = t2->next;
            t2->next = t1;
            if(temp != nullptr)
            {
                temp->next = t2;
            }
            temp = t1;
            t1 = t1->next;
            if (t1 != nullptr) 
                t2 = t1->next;
            else 
                t2 = nullptr;
        }
        return root;
        
    }
};
