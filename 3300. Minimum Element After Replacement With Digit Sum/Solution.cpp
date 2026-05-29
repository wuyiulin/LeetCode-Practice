class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        for(auto& num : nums)
        {
            int curr = 0;
            while(num)
            {
                curr += (num % 10);
                num /= 10;
            }
            num = curr;
        }

        return *min_element(nums.begin(), nums.end());
    }
};