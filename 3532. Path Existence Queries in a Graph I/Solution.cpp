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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        int m = queries.size();
        vector<bool> res(m, false);
        UnionFind uf(n);
        for(int i=1; i<n; i++)
        {
            if(nums[i] - nums[i - 1] <= maxDiff)
                uf.unite(i, i - 1);
        }

        for(int i=0; i<m; i++)
            res[i] = uf.connected(queries[i][0], queries[i][1]);
    
        return res;
    }
};