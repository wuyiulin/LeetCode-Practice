class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int steps = 0;
        while (!q.empty()) 
        {
            steps++;
            int sz = q.size();
            while (sz--) 
            {
                int cur = q.front(); q.pop();

                if (mp.count(arr[cur])) 
                {
                    for (int next : mp[arr[cur]]) 
                    {
                        if (next == n - 1) return steps;
                        if (!visited[next]) 
                        {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                    mp.erase(arr[cur]);
                }

                for (int next : {cur - 1, cur + 1}) 
                {
                    if (next < 0 || next >= n) continue;
                    if (next == n - 1) return steps;
                    if (!visited[next]) 
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};