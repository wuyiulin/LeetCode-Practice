class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n)
    {
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        return x == parent[x] ? x : find(parent[x]);
    }

    void Union(int x, int y)
    {
        int px = find(x), py = find(y);
        if(px == py)
            return;
        if(px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        UnionFind uf(26);
        int n = s1.size();
        for(int i=0; i<n; i++)
            uf.Union(s1[i] - 'a', s2[i] - 'a');

        for(auto& c : baseStr)
        {
            int i = uf.find(c - 'a');
            c = i + 'a';
        }

        return baseStr;
    }
};