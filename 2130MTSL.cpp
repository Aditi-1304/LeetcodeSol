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
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* temp;
        temp = head;
        while(temp != nullptr)
        {
            n++;
            temp = temp->next;
        }

        vector<int> a(n/2);
        int i=0;
        temp = head;

        while(i<n/2)
        {
            a[i++] = temp->val;
            temp = temp->next;
        }
        while(i<n)
        {
            a[n-i-1] += temp->val;
            i++;
            temp = temp->next;
        }
        
        return *max_element(a.begin(),a.end());
    }
};
