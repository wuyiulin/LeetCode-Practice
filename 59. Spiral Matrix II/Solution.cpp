class Solution {
using PII = pair<int, int>;
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0, tmp = 1;
        queue<PII> q;
        q.push({0, 0});
        while(!q.empty() && tmp <=n*n)
        {
            int r = q.front().first, c = q.front().second; q.pop();
            res[r][c] = tmp;
            tmp++;
            int newR = r + dirs[idx][0], newC = c + dirs[idx][1];
            if(newR<0 || newR>=n || newC<0 || newC>=n || res[newR][newC])
            {
                idx++;
                idx %= 4;
                newR = r + dirs[idx][0], newC = c + dirs[idx][1];
            }
            q.push({newR, newC});
        }

        return res;
    }
};