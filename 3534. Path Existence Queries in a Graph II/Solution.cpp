class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> vp(n);
        for(int i=0; i<n; i++)
            vp[i] = {nums[i], i};
        sort(vp.begin(), vp.end());
        int m = 20, r = n - 1, qs = queries.size();
        int bin[n][m];
        memset(bin, 0, sizeof(bin));
        for(int l=n-1; l>=0; l--)
        {
            while(vp[r].first - vp[l].first > maxDiff)
                r--;
            int i = vp[l].second, j = vp[r].second;
            bin[i][0] = j;
            for(int k=1; k<m; k++)
                bin[i][k] = bin[bin[i][k - 1]][k - 1];
        }
        vector<int> res(qs, 0);
        for(int i=0; i<qs; i++)
        {
            int u = queries[i][0], v = queries[i][1], d = 0;
            if(nums[u] > nums[v])
                swap(u, v);
            if(u == v)
            {
                res[i] = 0;
                continue;
            }
            for(int k=m-1; k>=0; k--)
            {
                if(nums[bin[u][k]] < nums[v])
                {
                    d |= 1 << k;
                    u = bin[u][k];
                }
            }

            res[i] = (nums[bin[u][0]] < nums[v]) ? -1 : (d + 1);
        }

        return res;
    }
};