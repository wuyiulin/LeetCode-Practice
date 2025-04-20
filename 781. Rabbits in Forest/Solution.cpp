class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int, int> rec;
        int res = 0;
        for(const auto& ans : answers) rec[ans]++;
        for(auto& it : rec)
        {
            res += (((it.second) / (it.first + 1)) * (it.first + 1));
            if((it.second) % (it.first + 1)) res += (it.first + 1);
        }

        return res;
    }
};

