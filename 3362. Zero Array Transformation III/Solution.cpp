class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) 
    {
        sort(queries.begin(), queries.end());
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<>> curr;
        int qIdx = 0, qs = queries.size();
        for(int i=0; i<nums.size(); i++)
        {
            while(qIdx < qs && queries[qIdx][0] <= i)
                available.push(queries[qIdx++][1]);
            while(!curr.empty() && curr.top() < i)
                curr.pop();
            while(nums[i] > curr.size())
            {
                if(available.empty() || available.top() < i) return -1;
                curr.push(available.top()); 
                available.pop();
            }
        }

        return available.size();
    }
};