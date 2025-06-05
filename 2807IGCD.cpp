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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* before = head;
        ListNode* after = head->next;
        while(after != nullptr)
        {
            ListNode* newNode = new ListNode();
            int d1 = before->val;
            int d2 = after->val;
            int g=1;
            for(int i=2;i<=max(d1,d2);i++)
            {
                if(d1%i == 0 && d2%i == 0 && g<i)
                {
                    g = i;
                }
            }
            newNode->val = g;
            newNode->next= after;
            before->next = newNode;
            before = before->next->next;
            after = after->next;
        }
        return head;
        
    }
};
