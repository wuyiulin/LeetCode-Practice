class Solution {
using LL = long long;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) 
    {
        int m = board.size(), n = board[0].size();
        vector<vector<LL>> dp(m, vector<LL>(n, 0));
        vector<vector<LL>> paths(m, vector<LL>(n, 0));
        vector<pair<int, int>>  dirs = {{-1, 0}, {-1, -1}, {0, -1}};
        LL mod = 1e9 + 7;
        board[0][0] = '0', board[m - 1][n - 1] = '0';
        paths[0][0] = 1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 'X') 
                    continue;
                for(const auto& d : dirs)
                {
                    int pr = i + d.first, pc = j + d.second;
                    if(pr < 0 || pc < 0 || board[pr][pc] == 'X' || paths[pr][pc] == 0)
                        continue;
                    if(dp[pr][pc] + (board[i][j] - '0') > dp[i][j])
                    {
                        dp[i][j] = dp[pr][pc] + (board[i][j] - '0');
                        paths[i][j] = paths[pr][pc];
                    }
                    else if(dp[pr][pc] + (board[i][j] - '0') == dp[i][j])
                    {
                        paths[i][j] += paths[pr][pc];
                    }
                    dp[i][j] %= mod;
                    paths[i][j] %= mod;
                }
            }
        }

        return {(int)dp[m - 1][n - 1], (int)paths[m - 1][n - 1]};
    }
};