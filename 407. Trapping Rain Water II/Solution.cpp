class Solution {
using PII = pair<int, int>;
public:
    int trapRainWater(vector<vector<int>>& hp) 
    {
        int m = hp.size(), n = hp[0].size(), maxH = 0, res = 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(r == 0 || r == m-1 || c == 0 || c == n-1)
                {
                    pq.push({hp[r][c], r*n + c});
                    vis[r][c] = true;
                }
            }
        }

        while(!pq.empty())
        {
            PII p = pq.top(); pq.pop();
            int h = p.first, r = p.second / n, c = p.second % n;
            maxH = max(maxH, h);
            for(const auto& dir : dirs)
            {
                int newR = r + dir[0], newC = c + dir[1];
                if(newR < 0 || newR >= m || newC < 0 || newC >= n || vis[newR][newC])
                    continue;
                vis[newR][newC] = true;
                if(hp[newR][newC] < maxH)
                    res += (maxH - hp[newR][newC]);
                pq.push({hp[newR][newC], newR * n + newC});
            }
        }

        return res;
    }
};

