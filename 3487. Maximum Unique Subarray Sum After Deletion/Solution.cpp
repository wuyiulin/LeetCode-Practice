class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int maxNum = INT_MIN;
        unordered_set<int> s;
        for(const auto& num : nums)
        {
            maxNum = max(maxNum, num);
            s.insert(num);
        }
        int res = 0;
        if(maxNum < 0)
            return maxNum;
        else
        {
            for(auto& n : s)
            {
                if(n > 0)
                    res += n;
            }
        }

        return res;
    }
};