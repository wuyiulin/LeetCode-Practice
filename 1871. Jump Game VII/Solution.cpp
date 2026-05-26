class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, 0), prefix(n + 1, 0);
        dp[0] = 1;
        prefix[1] = 1;

        for (int i = 1; i < n; i++) 
        {
            if (s[i] == '0') 
            {
                int lo = max(0, i - maxJump);
                int hi = i - minJump;
                if (hi >= 0) 
                {
                    int windowSum = prefix[hi + 1] - prefix[lo];
                    dp[i] = windowSum > 0 ? 1 : 0;
                }
            }
            prefix[i + 1] = prefix[i] + dp[i];
        }

        return dp[n - 1];
    }
};