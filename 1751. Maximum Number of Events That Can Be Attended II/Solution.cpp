class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int i=n-1; i>=0; i--)
        {
            int endTime = events[i][1], val = events[i][2];
            int idx = upper_bound(events.begin(), events.end(), endTime,
                        [](int endTime, const vector<int>& e)
                        {
                            return endTime < e[0];     
                        }) - events.begin();
            for(int j=1; j<=k; j++)
            {
                dp[i][j] = dp[i+1][j];   
                dp[i][j] = max(dp[i][j], dp[idx][j-1] + val);
            }
        }

        return dp[0][k];
    }
};