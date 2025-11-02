class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        int res = 0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(const auto& g : guards) 
            grid[g[0]][g[1]] = 2;
        for(const auto& w : walls) 
            grid[w[0]][w[1]] = 2;
        
        for(const auto& g : guards)
        {
            int gr = g[0], gc = g[1];
            for(const auto& d : dir)
            {
                for(int i = 1; i<max(m, n); i++)
                {
                    int new_gr = i*d[0] + gr, new_gc = i*d[1] + gc;
                    if(new_gr < 0 || new_gr >= m || new_gc < 0 || new_gc >= n || grid[new_gr][new_gc] == 2) 
                        break;
                    if(!grid[new_gr][new_gc]) 
                        grid[new_gr][new_gc] = 1; 
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++) 
                if(!grid[i][j]) 
                    res++;
        }

        return res;
    }
};


