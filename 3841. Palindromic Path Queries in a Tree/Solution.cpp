class Solution {
private:
    vector<vector<int>> table;
    vector<int> depth, parent, tin, tout, mask;
    int timer = 0;
    string str;
    
    static const int LOG = 17;  // 2^16 = 65536 > 5e4
    vector<vector<int>> up;

    vector<int> bit;
    int n;

    void dfs(int idx, int d, int p)
    {
        depth[idx] = d;
        parent[idx] = p;
        tin[idx] = timer++;
        mask[idx] = (p == -1 ? 0 : mask[p]) ^ (1 << (str[idx] - 'a'));
        for (int nb : table[idx])
        {
            if (nb == p)
                continue;
            dfs(nb, d + 1, idx);
        }
        tout[idx] = timer - 1;
    }

    void buildLifting()
    {
        up.assign(LOG, vector<int>(n));
        for (int x = 0; x < n; x++)
            up[0][x] = (parent[x] == -1) ? x : parent[x];   // root 的 parent 設成自己
        for (int k = 1; k < LOG; k++)
            for (int x = 0; x < n; x++)
                up[k][x] = up[k - 1][up[k - 1][x]];
    }

    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; k++)
            if ((diff >> k) & 1)
                u = up[k][u];
        if (u == v)
            return u;
        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[k][u] != up[k][v])
            {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    }

    void bitXor(int i, int val)
    {
        for(i++; i<=n; i += i & -i)
            bit[i] ^= val;
    }

    int prefixXor(int i)
    {
        int res = 0;
        for(i++; i>0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void rangeXor(int l, int r, int val)
    {
        bitXor(l, val);
        bitXor(r + 1, val);
    }

    int currMask(int x)
    {
        return mask[x] ^ prefixXor(tin[x]);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        str = s;
        table.assign(n, vector<int>());
        depth.assign(n, 0);
        parent.assign(n, -1);
        tin.assign(n, 0);
        tout.assign(n, 0);
        mask.assign(n, 0);
        bit.assign(n + 1, 0);
        timer = 0;
 
        for (const auto& e : edges)
        {
            table[e[0]].push_back(e[1]);
            table[e[1]].push_back(e[0]);
        }
        dfs(0, 0, -1);
        buildLifting();
 
        vector<bool> res;
        for (const string& q : queries)
        {
            istringstream ss(q);
            string type;
            ss >> type;
            if (type == "update")
            {
                int u;
                char c;
                ss >> u >> c;
                if (str[u] != c)
                {
                    int val = (1 << (str[u] - 'a')) ^ (1 << (c - 'a')); // 為了更新 str[u] 及其子樹的 mask
                    rangeXor(tin[u], tout[u], val);
                    str[u] = c;
                }
            }
            else
            {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int m = currMask(u) ^ currMask(v) ^ (1 << (str[l] - 'a'));
                res.push_back((m & (m - 1)) == 0);   // 最多一個 bit 是 1
            }
        }

        return res;            
    }
};