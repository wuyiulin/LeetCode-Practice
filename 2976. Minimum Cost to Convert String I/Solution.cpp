class Solution {
using LL = long long;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        LL res = 0;
        int m = source.size(), n = cost.size();
        vector<vector<LL>> dist(26, vector<LL>(26, LLONG_MAX));
        for(int i=0; i<n; i++)
        {
            int u = original[i] - 'a', v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], 1LL * cost[i]);
        }

        for(int i = 0; i < 26; i++) 
            dist[i][i] = 0;

        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                if(dist[j][i] < LLONG_MAX)
                {
                    for(int k=0; k<26; k++)
                    {
                        if(dist[i][k] < LLONG_MAX)
                        {
                            dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                        }
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            int u = source[i] - 'a', v = target[i] - 'a';
            if(dist[u][v] == LLONG_MAX)
                return -1;
            
            res += dist[u][v];
        }

        return res;
    }
};