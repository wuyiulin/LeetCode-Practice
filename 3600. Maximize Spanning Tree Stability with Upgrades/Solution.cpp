class Solution {
private:
    struct DSU 
    {
        vector<int> p, r;
        DSU(int n): p(n,-1), r(n,0) 
        {
            iota(p.begin(), p.end(), 0);
        }
        int find(int x) 
        {
            return p[x]==x ? x : p[x]=find(p[x]);
        }
        bool unite(int a, int b) 
        {
            a = find(a); 
            b = find(b);
            if (a == b) 
                return false;
            if (r[a] < r[b]) 
                swap(a,b);
            p[b] = a;
            if (r[a]==r[b]) 
                r[a]++;
            return true;
        }
    };

    bool isVaild(vector<vector<int>>& edges, int tar, int n, int k)
    {
        DSU dsu(n);
        int cnt = 0, super = 0;

        vector<vector<int>> candis;
        for(auto& e : edges)
        {
            int u = e[0], v = e[1], s = e[2], m = e[3];
            if(m)
            {   
                if(s < tar)
                    return false;
                dsu.unite(u, v);
                cnt++;
            }
            else
            {
                if(s >= tar)
                    candis.push_back({0, u, v});
                else if(s*2 >= tar)
                    candis.push_back({1, u, v});
            }
        }

        sort(candis.begin(), candis.end());

        for(auto& candi : candis)
        {
            int u = candi[1], v = candi[2];
            if(cnt == n-1)
                break;
            if(dsu.find(u) != dsu.find(v))
            {
                dsu.unite(u, v);
                cnt++;
                super += candi[0];
                if(super > k)
                    return false;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(dsu.find(i) != dsu.find(0))
                return false;
        }

        return cnt == n -1;
    }
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) 
    {
        int lo = 1, hi = 1e5 * 2;
        while(lo < hi)
        {
            int mid = lo + (hi - lo + 1) / 2;
            if(isVaild(edges, mid, n, k))
                lo = mid;
            else
                hi = mid - 1;
        }

        return isVaild(edges, lo, n, k) ? lo : -1;
        
    }
};