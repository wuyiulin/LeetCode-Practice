class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        unordered_map<char, unordered_set<int>> mp; // t, b, l, r
        mp['t'] = {2, 5, 6};
        mp['b'] = {2, 3, 4};
        mp['l'] = {1, 3, 5};
        mp['r'] = {1, 4, 5};
        unordered_map<int, unordered_set<char>> D; // t, b, l, r
        D[1] = {'l', 'r'};
        D[2] = {'t', 'b'};
        D[3] = {'l', 'b'};
        D[4] = {'b', 'r'};
        D[5] = {'l', 't'};
        D[6] = {'t', 'r'};
        unordered_map<char, vector<int>> dirs;
        dirs['t'] = {-1, 0};
        dirs['b'] = {1, 0};
        dirs['l'] = {0, -1};
        dirs['r'] = {0, 1};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        unordered_map<char, char> DT;
        DT['t'] = 'b';
        DT['b'] = 't';
        DT['l'] = 'r';
        DT['r'] = 'l';
        queue<vector<int>> q;
        q.push({0, 0, 0});
        vis[0][0] = true;
        while(!q.empty())
        {
            vector<int> v = q.front(); q.pop();
            char parentDir = v[2];
            int val = grid[v[0]][v[1]];
            if(v[0] == m - 1 && v[1] == n - 1)
                return true;
            for(const auto d : D[val])
            {
                if(d == parentDir)
                    continue;
                int newRow = v[0] + dirs[d][0], newCol = v[1] + dirs[d][1];
                if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || vis[newRow][newCol])
                    continue;
                int newVal = grid[newRow][newCol];
                if(!D[newVal].count(DT[d]))
                    continue;
                vis[newRow][newCol] = true;
                q.push({newRow, newCol, DT[d]});
            }
        }

        return false;
    }
};