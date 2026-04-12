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
        vector<vector<int>> dp(n, vector<int>(26, 1e9));
        for(int i=0; i<26; i++)
            dp[0][i] = 0;
        
        for(int i=1; i<n; i++)
        {
            int prev = word[i - 1] - 'A', curr = word[i] - 'A';
            int d = getDist(prev, curr);
            for(int j=0; j<26; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
                if(prev == j)
                {
                    for(int k=0; k<26; k++)
                    {
                        int dd = getDist(k, curr);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + dd);
                    }
                }
            }
        }

        res = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    
        return res;
    }
};