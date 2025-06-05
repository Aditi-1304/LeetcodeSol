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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int number = 0; //total local maxima and minima
        int minDistance=INT_MAX, maxDistance=0;
        int first = 0; // first local maxima or minima
        // int last = -1; // last local maxima or minima
        int p=0; // previous local maxima or minima
        int index = 1; //Node on
        ListNode* prev;
        prev = head;
        ListNode* curr = prev->next;
        ListNode* nextt = curr->next;
        while(nextt != nullptr)
        {
            index++; 
            int f=0;
            // Local maxima
            if(curr->val > prev->val && curr->val > nextt->val)
            {
                number++;
                if(first == 0)
                {
                    first = index;
                }
                if(p == 0)
                {
                    p = index;
                }
                f=1;
            }
            // Local minima
            else if(curr->val < prev->val && curr->val < nextt->val)
            {
                number++;
                if(first == 0)
                {
                    first = index;
                }
                if(p == 0)
                {
                    p = index;
                }
                f=1;
            }
            if(f == 1)
            {
                int m = index - p;
                if(m != 0)
                {
                    if(minDistance > m)
                    {
                        minDistance = m;
                    }
                }
                p = index;
            }
            prev = curr;
            curr = nextt;
            nextt = nextt->next;
        }
        maxDistance = p-first;
        if(number < 2)
        {
            return {-1,-1};
        }
        if(minDistance == 0)
        {
            return {maxDistance,maxDistance};
        }
        if(maxDistance == 0)
        {
            return {minDistance,minDistance};
        }
        return {minDistance,maxDistance};
    }
};
