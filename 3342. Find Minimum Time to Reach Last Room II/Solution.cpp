class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // dist, R, C
        while(!pq.empty())
        {
            auto [d, r, c] = pq.top(); pq.pop();
            if(r==m-1 && c==n-1) return d;
            if(d > dist[r][c]) continue;
            int time = (r + c) % 2 + 1;
            for(const auto& dir : dirs)
            {
                int newR = r + dir[0], newC = c + dir[1];
                if(0<=newR && newR<m && 0<=newC && newC<n)
                {
                    
                    int newDist = max(moveTime[newR][newC], d) + time;
                    if(newDist < dist[newR][newC])
                    {
                        dist[newR][newC] = newDist;
                        pq.push({newDist, newR, newC});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};