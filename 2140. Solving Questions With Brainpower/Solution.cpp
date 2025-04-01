class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for(int i=n-1; i>=0; i--)
        {
            int pts = questions[i][0], bp = questions[i][1];
            int next = min(i + bp + 1, n);
            dp[i] = max(dp[i + 1], dp[next] + pts);
        }

        return dp[0];
    }
};

