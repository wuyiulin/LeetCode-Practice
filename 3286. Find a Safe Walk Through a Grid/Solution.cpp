class Solution {
private:
    bool helper(vector<vector<int>>& grid, vector<int>& vis, int health)
    {
        int m = grid.size(), n = grid[0].size();
        int H = health + 1;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<tuple<int, int, int>> q; // r, c, h

        auto idx = [&](int r, int c, int h) 
        {
            return (r * n + c) * H + h;
        };

        int h0 = health - grid[0][0];
        q.push({0, 0, h0});
        vis[idx(0, 0, h0)] = 1;

        while (!q.empty())
        {
            auto [r, c, h] = q.front(); q.pop();
            if (h == 0)
                continue;
            if (r == m - 1 && c == n - 1 && h > 0)
                return true;

            for (const auto& d : dirs)
            {
                int newR = r + d[0], newC = c + d[1];
                if (newR < 0 || newR >= m || newC < 0 || newC >= n)
                    continue;
                int newH = h - grid[newR][newC];

                int id = idx(newR, newC, newH);
                if (vis[id])
                    continue;
                q.push({newR, newC, newH});
                vis[id] = 1;
            }
        }

        return false;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> vis(m * n * (health + 1), 0);

        return helper(grid, vis, health);
    }
};