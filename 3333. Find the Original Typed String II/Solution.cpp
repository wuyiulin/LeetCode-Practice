class Solution {
using LL = long long;
public:
    int possibleStringCount(string word, int k) 
    {
        const int MOD = 1e9 + 7;
        vector<int> table = {};
        int n = word.size();
        if(n < k)
            return 0;
        char curr = word[0];
        int cnt = 1; 
        for(int i=1; i<n; i++)
        {
            if(curr == word[i])
                cnt++;
            else
            {
                table.push_back(cnt);
                cnt = 1;
                curr = word[i];
            }
        }
        table.push_back(cnt);

        LL res = 1;
        for(const auto& t : table)
            res = (res * t) % MOD;
        if(table.size() >= k)
            return res;
        
        vector<int> dp(k, 0);
        dp[0] = 1;

        for(const auto& num : table)
        {
            vector<int> newDp(k, 0);
            LL sum = 0;
            for(int idx=0; idx<k; idx++)
            {
                if(idx > 0)
                    sum = (sum + dp[idx - 1]) % MOD;
                if(idx > num)
                    sum = (sum - dp[idx - num - 1] + MOD) % MOD;
                newDp[idx] = sum;
            }
            dp = newDp;
        }

        LL invalid = 0;
        for(int i=table.size(); i<k; i++)
            invalid = (invalid + dp[i]) % MOD;
        
        return (res - invalid + MOD) % MOD;
    }
};