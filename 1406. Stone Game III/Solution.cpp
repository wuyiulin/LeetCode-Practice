class Solution {
private:
    int dfs(vector<int>& stoneValue, vector<int>& dp, int& n, int index)
    {
        if(index >= n)
            return 0;
        if(dp[index] != INT_MAX)
            return dp[index];
        int diff = INT_MIN, curr = 0;
        for(int ts=0; ts<3 && index + ts < n; ts++)
        {
            curr += stoneValue[index + ts];
            diff = max(diff, curr - dfs(stoneValue, dp, n, index + ts + 1));
        }
        dp[index] = diff;

        return dp[index];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MAX);
        dfs(stoneValue, dp, n, 0);

        return dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice" : "Bob";
    }
};