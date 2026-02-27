class Solution {
public:
    int minOperations(string s, int k) 
    {
        int n = s.size(), zs = 0, res = 0;
        set<int> group[2];
        for(int i=0; i<n; i++)
        {
            group[i % 2].insert(i);
            if(s[i] == '0')
                zs++;
        }
        group[zs % 2].erase(zs);

        queue<int> q;
        q.push(zs);

        while(!q.empty())
        {
            for(int i=q.size(); i>0; i--)
            {
                int curr = q.front(); q.pop();
                if(!curr)
                    return res;
                
                int l = curr + k - 2 * min(curr, k);
                int r = curr + k - 2 * max(k - n + curr, 0);

                auto& g = group[l % 2];
                auto it = g.lower_bound(l);

                while(it != g.end() && *it <= r)
                {
                    q.push(*it);
                    it = g.erase(it);
                }
            }

            res++;
        }

        return -1;
    }
};