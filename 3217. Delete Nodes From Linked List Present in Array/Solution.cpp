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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* res = nullptr;
        ListNode* pre = nullptr;
        while(head != nullptr)
        {
            bool f = s.count(head->val);
            if(!f)
            {
                if(res == nullptr)
                    res = head;
                if(pre != nullptr)
                    pre->next = head;
                pre = head;
            }
            head = head->next;

            if(pre != nullptr)
                pre->next = nullptr;
        }

        return res;
    }
};