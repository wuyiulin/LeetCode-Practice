class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size(), curr = 0;
        string res = "";
        sort(nums.begin(), nums.end());
        for(const auto& num : nums)
        {
            if(stoi(num, nullptr, 2) != curr)
            {
                res = bitset<32>(curr).to_string();
                return res.substr(32 - n);
            }
            curr++;
        }
    
        res = bitset<32>(curr).to_string();

        return res.substr(32 - n);
    }
};