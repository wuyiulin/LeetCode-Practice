class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int cs = colors.size(), es = edges.size();
        vector<int> inDeg(cs, 0);
        vector<vector<int>> graph(cs);
        for(const auto& e : edges)
        {
            inDeg[e[1]]++;
            graph[e[0]].push_back(e[1]);
        }

        vector<vector<int>> colorTable(cs, vector<int>(26, 0));
        queue<int> q;
        for(int i=0; i<cs; i++)
        {
            if(!inDeg[i])
                q.push(i);
        }

        int res = 0, visited = 0;
        while(!q.empty())
        {
            visited++;
            int nodeIdx = q.front(); q.pop();
            int c = colors[nodeIdx] - 'a';
            colorTable[nodeIdx][c]++;
            res = max(res, colorTable[nodeIdx][c]);
            
            for(const auto& v : graph[nodeIdx])
            {
                for(int i=0; i<26; i++)
                {
                    colorTable[v][i] = max(colorTable[v][i], colorTable[nodeIdx][i]);
                }
                if(!--inDeg[v])
                    q.push(v);
            }
        }

        return visited == cs ? res : -1;
    }
};