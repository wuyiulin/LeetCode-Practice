class Solution {
private:
    pair<int, unordered_set<int>> dfs(const vector<vector<int>>& tree, int u, int prev, vector<int>& subXors, vector<unordered_set<int>>& child)
    {
        for(const int& v : tree[u])
        {
            if(v == prev)
                continue;
            const auto& [vXor, vChild] = dfs(tree, v, u, subXors, child);
            subXors[u] ^= vXor;
            child[u].insert(vChild.begin(), vChild.end());
        }

        return {subXors[u], child[u]};
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n = nums.size();
        int xorSum = accumulate(nums.begin(), nums.end(), 0, bit_xor());
        vector<int> subXors(nums);
        vector<vector<int>> tree(n);
        vector<unordered_set<int>> child(n);

        for(int i=0; i<n; i++)
            child[i].insert(i);
        
        for(const vector<int>& edge : edges)
        {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(tree, 0, -1, subXors, child);

        int res = INT_MAX;

        for(int i=0; i<edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            if(child[a].contains(b))
                swap(a, b);
            for(int j=0; j<i; j++)
            {
                int c = edges[j][0];
                int d = edges[j][1];
                if(child[c].contains(d))
                    swap(c, d);
                vector<int> cands;
                if(a != c && child[a].contains(c))
                    cands = {subXors[c], subXors[a] ^ subXors[c], xorSum ^ subXors[a]};
                else if(a != c && child[c].contains(a))
                    cands = {subXors[a], subXors[c] ^ subXors[a], xorSum ^ subXors[c]};
                else
                    cands = {subXors[a], subXors[c], xorSum ^ subXors[a] ^ subXors[c]};
                res = min(res, ranges::max(cands) - ranges::min(cands));
            }
        }

        return res;
    }
};