class Solution
{
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        queue<int> q;
        q.push(node1);
        dist1[node1] = 0;
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            int next = edges[curr];
            if(next != -1 && dist1[next] == -1)
            {
                dist1[next] = dist1[curr] + 1;
                q.push(next);
            }
        }

        q.push(node2);
        dist2[node2] = 0;
        while(!q.empty())
        {
            int curr = q.front(); q.pop();
            int next = edges[curr];
            if(next != -1 && dist2[next] == -1)
            {
                dist2[next] = dist2[curr] + 1;
                q.push(next);
            }
        }

        int resNode = -1, minMaxDist = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(dist1[i] == -1 || dist2[i] == -1)
                continue;
            int currMaxDist = max(dist1[i], dist2[i]);
            if(currMaxDist < minMaxDist || (currMaxDist == minMaxDist && i < resNode))
            {
                minMaxDist = currMaxDist;
                resNode = i;
            }
        }

        return resNode;
    }
};
