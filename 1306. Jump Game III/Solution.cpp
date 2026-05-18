class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        int n = arr.size();
        bool vis[n];
        fill(vis, vis + n, false);
        queue<int> q = {};
        q.push(start);

        while(!q.empty())
        {
            int i = q.front(); q.pop();
            if(!arr[i])
                return true;
            int l = i - arr[i], r = i + arr[i];
            if(0 <= l && l < n && !vis[l])
            {
                q.push(l);
                vis[l] = true;
            }
            if(0 <= r && r < n && !vis[r])
            {
                q.push(r);
                vis[r] = true;
            }
        }

        return false;
    }
};