class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) 
  {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) 
  {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) 
    {
      id[i] = j;
    } 
    else if (rank[i] > rank[j]) 
    {
      id[j] = i;
    } 
    else 
    {
      id[i] = j;
      ++rank[j];
    }
  }

  int find(int u) 
  {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) 
    {
        int n =  source.size(), res = 0;
        UnionFind uf(n);
        vector<unordered_map<int, int>> table(n);
        for(const auto& all : allowedSwaps)
        {
            int a = all[0], b = all[1];
            uf.unionByRank(a, b);
        }

        for(int i=0; i<n; i++)
            ++table[uf.find(i)][source[i]];
        
        for(int i=0; i<n; i++)
        {
            int gIdx = uf.find(i);
            unordered_map<int, int>& count = table[gIdx];
            if(!count.count(target[i]))
                res++;
            else if(--count[target[i]] == 0)
                count.erase(target[i]);
        }

        return res;
    }
};