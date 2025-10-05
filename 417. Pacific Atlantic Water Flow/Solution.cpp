class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visP(m, vector<int>(n, 0)), visA(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<int> qp, qa;
        vector<vector<int>> res = {};
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                int idx = r * n + c;
                if(r==0 || c==0)
                    qp.push(idx);
                if(r==m-1 || c == n-1)
                    qa.push(idx);
            }
        }
        while(!qp.empty())
        {
            int r = qp.front() / n, c = qp.front() % n; qp.pop();
            int val = heights[r][c];
            visP[r][c] = 1;
            for(const auto& dir : dirs)
            {
                int newR = r + dir[0], newC = c + dir[1];
                if(newR < 0 || newR >=m || newC < 0 || newC >= n || heights[newR][newC] < val || visP[newR][newC])
                    continue;
                qp.push(newR * n + newC);
            }
        }
        while(!qa.empty())
        {
            int r = qa.front() / n, c = qa.front() % n; qa.pop();
            int val = heights[r][c];
            visA[r][c] = 1;
            for(const auto& dir : dirs)
            {
                int newR = r + dir[0], newC = c + dir[1];
                if(newR < 0 || newR >=m || newC < 0 || newC >= n || heights[newR][newC] < val || visA[newR][newC])
                    continue;
                qa.push(newR * n + newC);
            }
        }

        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(visP[r][c] && visA[r][c])
                    res.push_back({r, c});
            }
        }

        return res;
    }
};