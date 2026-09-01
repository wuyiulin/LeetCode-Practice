class Solution {
public:
    int minMoves(vector<string>& classroom, int energy)
    {
        int m = classroom.size(), n = classroom[0].size(), cnt = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int startRow = -1, startCol = -1;
        vector<vector<int>> bitOf(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (classroom[i][j] == 'S')
                {
                    startRow = i;
                    startCol = j;
                }
                else if (classroom[i][j] == 'L')
                {
                    bitOf[i][j] = cnt;
                    cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int fullMask = (1 << cnt) - 1;
        int E = energy + 1;
        int MASK = 1 << cnt;

        vector<bool> vis((size_t)m * n * E * MASK, false);
        auto idx = [&](int r, int c, int e, int mask)
        {
            return (size_t)((r * n + c) * E + e) * MASK + mask;
        };

        queue<tuple<int, int, int, int>> q;
        q.push({startRow, startCol, energy, fullMask});
        vis[idx(startRow, startCol, energy, fullMask)] = true;

        int res = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [row, col, currEnergy, currMask] = q.front();
                q.pop();

                if (currMask == 0)
                    return res;

                if (currEnergy <= 0)
                    continue;

                for (const auto& d : dirs)
                {
                    int newRow = row + d[0], newCol = col + d[1];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
                        continue;
                    if (classroom[newRow][newCol] == 'X')
                        continue;

                    int nxtEnergy = (classroom[newRow][newCol] == 'R') ? energy : currEnergy - 1;
                    int nxtMask = currMask;
                    if (classroom[newRow][newCol] == 'L')
                    {
                        nxtMask &= ~(1 << bitOf[newRow][newCol]);
                    }

                    size_t id = idx(newRow, newCol, nxtEnergy, nxtMask);
                    if (!vis[id])
                    {
                        vis[id] = true;
                        q.push({newRow, newCol, nxtEnergy, nxtMask});
                    }
                }
            }
            res++;
        }

        return -1;
    }
};