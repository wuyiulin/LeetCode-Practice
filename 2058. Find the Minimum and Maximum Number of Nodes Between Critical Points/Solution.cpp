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
        long long prev = head->next->val - head->val;
        int fIdx = -1, rIdx = -1, idx = 1, last = -1;
        head = head->next;
        vector<int> res = {INT_MAX, -1};
        while(head->next != nullptr)
        {
            int curr = head->next->val - head->val;
            if(prev * curr < 0)
            {
                if(last != -1)
                    res[0] = min(res[0], idx - last);
                last = idx;
                if(fIdx == -1)
                    fIdx = idx;
                rIdx = idx;
            }
            prev = curr;
            head = head->next;
            idx++;
        }
        res[1] = rIdx != fIdx ? rIdx - fIdx : -1;
        
        return res[1] == -1 ? vector<int>{-1, -1} : res;
    }
};