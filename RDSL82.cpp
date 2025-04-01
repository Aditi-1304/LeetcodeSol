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
        ListNode* curr = head;
        ListNode* prev = head;
        int f=0,p=0;
        while(curr!=nullptr && curr->next != nullptr)
        {
            if(curr->next != nullptr && curr->val != curr->next->val)
            {
                prev = curr;
                curr = curr->next;
            }
            while(curr->next != nullptr && curr->val == curr->next->val) 
            {
                curr=curr->next;
                f=1;
            }
            while(prev == head && prev->next != nullptr && prev->val == prev->next->val) 
            {
                head = head->next;
                prev=prev->next;
                p=1;
            }
            
            if(f==1)
            {
                f=0;
                curr = curr->next;
            }
            if(p==1)
            {
                head = head->next;
                prev=prev->next;
                p=0;
            }
            else
            {
                prev->next = curr;
            }
            
        }
        return head;
    }
};
