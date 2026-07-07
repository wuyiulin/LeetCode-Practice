class Solution {
using LL = long long;
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) 
    {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n); // v, w
        vector<int> indeg(n, 0);
        vector<int> weights;

        for(auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indeg[v]++;
            weights.push_back(w);
        }

        vector<int> topo;
        vector<int> indegCopy = indeg;
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indegCopy[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(auto& [v, w] : adj[u])
                if(--indegCopy[v] == 0)
                    q.push(v);
        }

        sort(weights.begin(), weights.end());
        weights.erase(unique(weights.begin(), weights.end()), weights.end());

        const LL INF = LLONG_MAX / 2;
        auto check = [&](int t) -> bool {
            vector<LL> dist(n, INF);
            dist[0] = 0;
            for(int u : topo)
            {
                if(dist[u] >= INF || !online[u])
                    continue;
                for(auto& [v, w] : adj[u])
                {
                    if(w < t || !online[v])
                        continue;
                    if(dist[u] + w < dist[v])
                        dist[v] = dist[u] + w;
                }
            }
            return dist[n - 1] <= k;
        };

        int lo = 0, hi = (int)weights.size() - 1, res = -1;
        while(lo <= hi)
        {
            int mid = (hi - lo) / 2 + lo;
            if(check(weights[mid]))
            {
                res = weights[mid];
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        return res;
    }   
};