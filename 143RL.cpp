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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* slow=head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* t1 = slow->next;
        slow->next = nullptr;
        slow = t1;

        while(slow != nullptr)
        {
            st.push(slow);
            slow=slow->next;
        }

        ListNode* temp = head;
        while(!st.empty() && temp != nullptr && temp->next != nullptr)
        {
            ListNode* t2 = temp->next;
            temp->next = st.top();
            temp->next->next = t2;
            temp = temp->next->next;
            st.pop();
        }
    }
};
