class Solution
{
public:
    int minMoves(vector<string>& classroom, int energy) 
    {
        vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        int RS = classroom.size(), CS = classroom[0].size();

        unordered_map<int, unordered_map<int, int>> coord_to_id;
        int sr = 0, sc = 0, litter_count = 0;

        for (int i = 0; i < RS; i++) 
        {
            for (int j = 0; j < CS; j++) 
            {
                if (classroom[i][j] == 'S') 
                {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') 
                {
                    coord_to_id[i][j] = litter_count;
                    litter_count++;
                }
            }
        }

        if (!litter_count)
            return 0;

        vector<vector<unordered_map<int, int>>> vis(RS, vector<unordered_map<int, int>>(CS));
        queue<tuple<int, int, int, int, int>> q;  // (r, c, energy, steps, mask)

        q.push({sr, sc, energy, 0, 0});
        vis[sr][sc][0] = energy;

        while (!q.empty()) 
        {
            auto [r, c, e, steps, mask] = q.front();
            q.pop();

            if (classroom[r][c] == 'L') 
            {
                if (coord_to_id.count(r) && coord_to_id[r].count(c)) 
                {
                    int id = coord_to_id[r][c];
                    mask |= (1 << id);
                }

                if (mask == (1 << litter_count) - 1) 
                    return steps;
            }

            if (classroom[r][c] == 'R') 
                e = energy;

            if (!e) 
                continue;

            for (const auto& dir : dirs) 
            {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= RS || nc < 0 || nc >= CS || classroom[nr][nc] == 'X') 
                    continue;

                int new_energy = e - 1;

                if (vis[nr][nc].count(mask) && vis[nr][nc][mask] >= new_energy) 
                    continue;

                vis[nr][nc][mask] = new_energy;
                q.push({nr, nc, new_energy, steps + 1, mask});
            }
        }

        return -1;
    }
};