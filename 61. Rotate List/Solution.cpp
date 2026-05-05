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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int n = 0;
        ListNode *res = head, *tmp = head, *last = NULL;
        while(tmp != NULL)
        {
            n++;
            last = tmp;
            tmp = tmp->next;
        }
        if(!n)
            return head;
        k %= n;
        int step = n - k - 1;
        tmp = head;
        if(k)
        {
            while(step)
            {
                tmp = tmp->next;
                step--;
            }
            res = tmp->next;
            tmp->next = nullptr;
            last->next = head;
        }
        
        return res;
    }
};