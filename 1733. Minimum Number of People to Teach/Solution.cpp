class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) 
    {
        int m = languages.size(); // 總人數 m
        vector<unordered_set<int>> lans(m);
        unordered_set<int> candidates;
        for(int i=0; i<m; i++)
            for(const auto& l : languages[i])
                lans[i].insert(l);
        for(const auto& fs : friendships)
        {
            int u = fs[0] - 1, v = fs[1] - 1;
            bool f = true;
            for(const auto& l : lans[u])
            {
                if(lans[v].count(l))
                {
                    f = false;
                    break;
                }
            }
            if(f)
            {
                candidates.insert(u);
                candidates.insert(v);
            }
        }
        int res = INT_MAX;
        for(int l=1; l<=n; l++)
        {
            int cnt = 0;
            for(const auto& can : candidates)
            {
                if(lans[can].count(l)) cnt++;
            }
            res = min(res, (int)candidates.size() - cnt);
        }
    
        return res;
    }
};