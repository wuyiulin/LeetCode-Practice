class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res = 0;
        int left = 0;
        unordered_map<int, int> table;
        for(const auto& f : fruits)
        {
            if(!table.count(f))
            {
                while(table.size() == 2)
                {
                    table[fruits[left]]--;
                    if(!table[fruits[left]])
                        table.erase(fruits[left]);
                    left++;
                }
            }
            table[f]++;

            int curr = 0;
            for(auto& [key, val] : table)
                curr += val;
            res = max(res, curr);
        }

        return res;
    }
};

