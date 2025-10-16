class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int, int> table;
        int curr = 0;
        for(auto& num : nums)
        {
            if(num == curr)
            {
                curr++;
                continue;
            }
            if(num < 0)
            {
                num %= value;
                num += value;
            }
            
            table[num % value]++;
        }

        while(!table.empty())
        {
            int tar = curr % value;
            if(!table.count(tar))
                return curr;
            table[tar]--;
            curr++;
            if(!table[tar])
                table.erase(tar);
        }

        return curr;
    }
};