class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> res = {};
        for(auto& num : nums)
        {
            int start = res.size();
            while(num)
            {
                res.push_back(num%10);
                num /= 10;
            }
            reverse(res.begin() + start, res.end());
        }
            
        return res;
    }
};