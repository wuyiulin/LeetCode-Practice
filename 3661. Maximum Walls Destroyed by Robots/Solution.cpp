class Solution {
using LL = long long;
private:
    int countWalls(vector<int>& walls, LL l, LL r)
    {
        auto it_start = lower_bound(walls.begin(), walls.end(), l);
        auto it_end = upper_bound(walls.begin(), walls.end(), r);
        int count = distance(it_start, it_end);

        return count;
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) 
    {
        int n = robots.size();
        int table[n], dp[n][2];
        memset(table, 0, sizeof(table));
        memset(dp, 0, sizeof(dp));
        iota(table, table + n, 0);
        sort(table, table + n, [&](int i, int j){
            return robots[i] < robots[j];
        });

        sort(walls.begin(), walls.end());
        
        for(int i = 0; i < n; i++) 
        {
            LL loc = robots[table[i]], dis = distance[table[i]];
            LL l_limit = i ? max((LL)robots[table[i-1]], loc - dis) : loc - dis;
            LL r_limit = (i != n-1) ? min((LL)robots[table[i+1]], loc + dis) : loc + dis;

            int lws = countWalls(walls, l_limit, loc);
            int rws = countWalls(walls, loc, r_limit);

            if (i == 0) 
            {
                dp[i][0] = lws; 
                dp[i][1] = rws;
            } 
            else 
            {
                int self_wall = countWalls(walls, loc, loc);
                int prev_loc = robots[table[i-1]];
                int prev_wall = countWalls(walls, prev_loc, prev_loc);

                int r_opt1 = dp[i-1][0] + rws;
                LL prev_r_reach = prev_loc + distance[table[i-1]];
                int r_opt2 = dp[i-1][1] + rws - (prev_r_reach >= loc ? self_wall : 0);
                dp[i][1] = max(r_opt1, r_opt2);

                int l_opt1 = dp[i-1][0] + lws - (l_limit <= prev_loc ? prev_wall : 0);
                LL overlap_l = max(l_limit, (LL)prev_loc);
                LL overlap_r = min(loc, (LL)prev_r_reach);
                int overlap = (overlap_l <= overlap_r) ? countWalls(walls, overlap_l, overlap_r) : 0;
                int l_opt2 = dp[i-1][1] + lws - overlap;
                
                dp[i][0] = max(l_opt1, l_opt2);
            }
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};