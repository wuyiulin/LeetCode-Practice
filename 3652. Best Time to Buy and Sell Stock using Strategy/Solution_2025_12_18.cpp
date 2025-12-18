class Solution {
using LL = long long;
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) 
    {
        int n = prices.size();
        vector<LL> prefix(n, 0);
        vector<LL> pos(n, 0);
        prefix[0] = prices[0] * strategy[0];
        pos[0] = prices[0];

        for(int i=1; i<n; i++)
        {
            prefix[i] = prices[i] * strategy[i] + prefix[i - 1];
            pos[i] = prices[i] + pos[i - 1];
        }
        LL res = prefix.back();    
        
        for(int i=0; i<n-(k-1); i++)
        {
            LL head = i ? prefix[i-1] : 0, tail = prefix.back() - prefix[i+k-1];
            int l = i + k/2 - 1, r = i + k - 1;
            LL body = pos[r] - pos[l];
            res = max(res, head + body + tail);
        }

        return res;
    }
};