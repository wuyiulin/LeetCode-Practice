class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) 
            dp[i] = piles[i];

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++) 
            {
                int j = i + len - 1;
                dp[i] = max(piles[i] - dp[i+1], piles[j] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
};