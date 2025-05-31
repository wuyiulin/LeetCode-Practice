class Solution {
using PII = pair<int, int>;
int rs, cs, n;

private:
    int mapFunc(vector<vector<int>>& board, int x)
    {
        int rIdx = n - 1 - (x - 1) / n;
        int cIdx = (!((n - 1 - rIdx) % 2)) ? ((x - 1) % n) : (n - 1 - ((x - 1) % n));

        return board[rIdx][cIdx];
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        n = board.size();
        int n2 = n * n;
        vector<bool> vis(n2 + 1, false);
        queue<PII> q;
        q.push({1, 0});
        while(!q.empty())
        {
            auto [idx, val] = q.front(); q.pop();
            if (vis[idx])
                continue;
            vis[idx] = true;

            if (idx == n2)
                return val;

            for (int i = 1; i <= 6 && idx + i <= n2; ++i)
            {
                int next = idx + i;
                int m = mapFunc(board, next);
                if (m != -1)
                    next = m;

                if (!vis[next])
                    q.push({next, val + 1});
            }
        }

        return -1;
    }
};