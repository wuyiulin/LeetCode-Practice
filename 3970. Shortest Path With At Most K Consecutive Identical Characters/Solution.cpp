class Solution {
using TP = tuple<int, int, char, int>;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) 
    {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& e : edges)
            graph[e[0]].push_back({e[1], e[2]});

        // dist, node, prevChar, cnt
        priority_queue<TP, vector<TP>, greater<TP>> pq;
        set<tuple<int, char, int>> visited;

        pq.push({0, 0, labels[0], 1});

        while(!pq.empty())
        {
            auto [dist, node, prevChar, cnt] = pq.top(); pq.pop();
            if(node == n - 1)
                return dist;
            
            auto state = make_tuple(node, prevChar, cnt); 
            if(visited.count(state))
                continue;
            
            visited.insert(state);
            for(const auto& [next, weight] : graph[node])
            {
                char nextChar = labels[next];
                if(nextChar == prevChar)
                {
                    if(cnt < k)
                    {
                        auto nextState = make_tuple(next, nextChar, cnt + 1);
                        if(!visited.count(nextState))
                            pq.push({dist + weight, next, nextChar, cnt + 1});
                    }
                }
                else
                {
                    auto nextState = make_tuple(next, nextChar, 1);
                    if(!visited.count(nextState))
                        pq.push({dist + weight, next, nextChar, 1});
                }
            }

        }
        return -1;
    }
};