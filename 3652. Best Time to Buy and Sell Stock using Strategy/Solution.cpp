class Solution {
using LL = long long;
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) 
    {
        LL Sum = 0, comp = 0, n = prices.size();
        vector<LL> prefix(n + 1, 0);
        vector<LL> allPlus(n + 1, 0);
        for(int i=0; i<=n; i++)
        {
            prefix[i] = Sum;
            if(i<n)
            {
                Sum += (prices[i] * strategy[i]);
                allPlus[i+1] = allPlus[i] + prices[i];
            }
        }
        comp = Sum;
        for(int i=0; i<=n-k; i++)
        {
            LL tmp = allPlus[i+k] - allPlus[i + (k/2)];
            if(tmp > prefix[i+k] - prefix[i])
                comp = max(comp, prefix.back() + (tmp - (prefix[i+k] - prefix[i])));
        }

        return max(Sum, comp);
    }
};