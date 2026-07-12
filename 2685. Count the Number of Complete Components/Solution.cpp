class UnionFind {
private:
    vector<int> parent;
    vector<int> rank_;
    int count_;           

public:
    UnionFind(int n) : parent(n), rank_(n, 0), count_(n) 
    {
        for (int i = 0; i < n; i++) 
        {
            parent[i] = i;
        }
    }

    int find(int x) 
    {
        if (parent[x] != x) 
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (rank_[rootX] < rank_[rootY]) 
        {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        if (rank_[rootX] == rank_[rootY]) 
        {
            rank_[rootX]++;
        }
        count_--;
        return true;
    }

    bool connected(int x, int y) 
    {
        return find(x) == find(y);
    }

    int count() 
    {
        return count_;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        int res = 0;
        UnionFind uf(n);
        unordered_map<int, int> nodeCount, edgeCount;
        for(auto& e : edges)
            uf.unite(e[0], e[1]);
            
        for(int i=0; i<n; i++)
            nodeCount[uf.find(i)]++;
        for(auto& e : edges)
            edgeCount[uf.find(e[0])]++;
        
        for(auto& [root, k] : nodeCount)
        {
            if(edgeCount[root] == (nodeCount[root] * (nodeCount[root] - 1) / 2))
                res++;
        }
        

        return res;
    }
};