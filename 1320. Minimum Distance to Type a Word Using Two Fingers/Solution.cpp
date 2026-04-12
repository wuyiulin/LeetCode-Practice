class Solution {
private:
    int getDist(int i, int j)
    {
        int x1 = i / 6, y1 = i % 6;
        int x2 = j / 6, y2 = j % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    int minimumDistance(string word) 
    {
        int n = word.size(), res = 1e9;
        vector<vector<int>> dp(2, vector<int>(26, 1e9));
        for(int i=0; i<26; i++)
            dp[0][i] = 0;
        
        for(int i=1; i<n; i++)
        {
            fill(dp[1].begin(), dp[1].end(), 1e9);
            int prev = word[i - 1] - 'A', curr = word[i] - 'A';
            int d = getDist(prev, curr);
            for(int j=0; j<26; j++)
            {
                dp[1][j] = min(dp[1][j], dp[0][j] + d);
                if(prev == j)
                {
                    for(int k=0; k<26; k++)
                    {
                        int dd = getDist(k, curr);
                        dp[1][j] = min(dp[1][j], dp[0][k] + dd);
                    }
                }
            }
            dp[0] = dp[1];
        }

        res = *min_element(dp[0].begin(), dp[0].end());
    
        return res;
    }
};