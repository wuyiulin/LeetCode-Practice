class Solution {
private:
    bool check(int m, int n, int r, int c) {
        return !(r < 0 || r >= m || c < 0 || c >= n);
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        vector<pair<int, int>> rec;
        unordered_map<int, int> value_to_count;
        
        for (const auto& row : grid) {
            for (const auto& val : row) {
                if (value_to_count.find(val) == value_to_count.end()) {
                    value_to_count[val] = 0;
                    rec.push_back({val, 0});
                }
            }
        }
        
        sort(rec.begin(), rec.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = 0;
        
        int cnt = 0, maxNum = rec[0].first, maxIdx = 1;
        
        while (!pq.empty()) {
            vector<int> node = pq.top(); pq.pop();
            
            while (maxNum < node[0]) {
                rec[maxIdx - 1].second = cnt;
                maxNum = rec[maxIdx].first;
                maxIdx++;
            }

            for (const auto& dir : dirs) {
                int newR = node[1] + dir[0], newC = node[2] + dir[1];
                if (check(m, n, newR, newC) && grid[newR][newC]) {
                    pq.push({grid[newR][newC], newR, newC});
                    grid[newR][newC] = 0;  
                }
            }
            cnt++;
        }

        int qs = queries.size();
        vector<int> res(qs, 0);

        for (int i = 0; i < qs; i++) {
            auto it = lower_bound(rec.begin(), rec.end(), make_pair(queries[i], 0));
            if (it == rec.begin()) res[i] = 0;
            else if (it == rec.end()) res[i] = m * n;
            else res[i] = prev(it)->second;
        }

        return res;
    }
};