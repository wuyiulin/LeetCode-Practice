class Solution {
using LL = long long;
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        int minNum = INT_MAX;
        vector<int> swapList;
        unordered_map<int, int> count;
        for(const int b : basket1)
        {
            count[b]++;
            minNum = min(minNum, b);
        }
        for(const int b : basket2)
        {
            count[b]--;
            minNum = min(minNum, b);
        }
        for(const auto& [key, freq] : count)
        {
            if(freq % 2)
                return -1;
            for(int i=0; i<abs(freq)/2; i++)
            {
                swapList.push_back(key);
            }
        }
        const auto it = swapList.begin() + swapList.size()/2;
        nth_element(swapList.begin(), it, swapList.end());
        LL res = 0;
        for(int i=0; i<swapList.size()/2; i++)
            res += min(minNum*2, swapList[i]);

        return res;

    }
};