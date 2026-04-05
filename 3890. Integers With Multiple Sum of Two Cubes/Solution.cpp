class Solution {
using LL = long long;
public:
    vector<int> findGoodIntegers(int n) 
    {
        vector<int> res = {};
        unordered_map<long long, int> table;
        int upBound = cbrt(n);
        if(upBound <= 0)
            return res;

        for(int a=0; a<=upBound; a++)
        {
            for(int b=a; b<=upBound; b++)
            {
                int curr = a*a*a + b*b*b;
                if(curr > n)
                    break;
                else
                    table[curr]++;
            }
        }
        for (auto const& [num, count] : table) 
        {
            if (count >= 2)
                res.push_back(num);
        }
        sort(res.begin(), res.end());

        return res;
    }
};