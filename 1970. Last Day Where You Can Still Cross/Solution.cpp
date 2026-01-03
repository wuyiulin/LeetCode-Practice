class Solution {
using PII = pair<int, int>;
private:
    bool helper(int row, int col, vector<vector<int>>& cells, int idx)
    {
        vector<vector<int>> mat(row, vector<int>(col, 0));
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<PII> q;
        for(int i=0; i<idx; i++)
            mat[cells[i][0]][cells[i][1]] = 1;
        for(int i=0; i<col; i++)
        {
            if(!mat[0][i])
            {
                q.push({0, i});
                mat[0][i] = 1;
            }
        }
        while(!q.empty())
        {
            PII p = q.front(); q.pop();
            for(const auto& dir : dirs)
            {
                int newR = p.first + dir[0], newC = p.second + dir[1];
                if(newR < 0 || newR >= row || newC < 0 || newC >= col || mat[newR][newC])
                    continue;
                if(newR == row - 1)
                    return true;
                q.push({newR, newC});
                mat[newR][newC] = 1;
            }
        }

        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int n = row * col, res = 0;
        int l = 0, r = cells.size() - 1;
        for(auto& cell : cells)
        {
            cell[0] -= 1;
            cell[1] -= 1;
        }
        while(l<r)
        {
            int mid = l + (r - l + 1) / 2;
            if(helper(row, col, cells, mid))
                l = mid;
            else
                r = mid - 1;
        }

        return r;
    }
};