class Solution {
using PII = pair<int, int>;
public:
    int minCost(int n, vector<vector<int>>& edges) 
    {
        vector<vector<PII>> graph(n);
        for(auto& e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        const int upper = INT_MAX / 2;
        vector<int> dist(n, upper);
        dist[0] = 0;

        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, 0});

        while(!pq.empty())
        {
            auto [d, u] = pq.top(); pq.pop();
            if(d > dist[u])
                continue;
            if(u == n - 1)
                return d;
            
            for(auto& [v, w] : graph[u])
            {
                int newD = d + w;
                if(newD < dist[v])
                {
                    dist[v] = newD;
                    pq.push({newD, v});
                }
            }
        }

        return -1;
    }
};