class Solution {
using PII = pair<int, int>;
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0, n = grid.size();
        priority_queue<PII, vector<PII>, greater<>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0});

        while(!pq.empty())
        {
            int val = pq.top().first, idx = pq.top().second;
            pq.pop();
            res = max(res, val);
            if(idx == n*n-1)
                break;
            int r = idx / n, c = idx % n;
            vis[r][c] = true;
            for(const auto& dir : dirs)
            {
                int newR = r + dir[0], newC = c + dir[1];
                if(newR < 0 || newR >= n || newC < 0 || newC >= n || vis[newR][newC])
                    continue;
                pq.push({grid[newR][newC], newR*n + newC});
            }
        }

        return res;
    }
};