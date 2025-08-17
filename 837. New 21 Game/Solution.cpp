class Solution {
public:
    double new21Game(int n, int k, int maxPts) 
    {
        if(!k || n >= k + maxPts)
            return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double ws = 1.0, res = 0.0;
        for(int i=1; i<=n; i++)
        {
            dp[i] = ws / maxPts;
            if(i < k)
                ws += dp[i];
            else
                res += dp[i];
            if(i - maxPts >= 0)
                ws -= dp[i - maxPts];
        }

        return res;
    }
};