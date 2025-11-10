class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int res = 0;
        stack<int> st;
        st.push(0);
        for(const auto& num : nums)
        {
            while(!st.empty() && num < st.top())
                st.pop();
            if(st.top() < num)
            {
                res++;
                st.push(num);
            }
        }

        return res;
    }
};