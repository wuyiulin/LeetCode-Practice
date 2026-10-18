class Solution {
    using LL = long long;
    static const int MOD = 1e9 + 7;
    vector<vector<LL>> pascal;
private:
    LL dfs(const vector<int>& v)
    {
        int n = v.size();
        if(n <= 2)
            return 1;
        vector<int> L, R;
        for(int i=1; i<n; i++)
            (v[i] < v[0] ? L : R).push_back(v[i]);

        return (pascal[n - 1][L.size()] * dfs(L) % MOD) * (dfs(R) % MOD) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascal.assign(n + 1, vector<LL>(n + 1, 0));
        for(int i=0; i<=n; i++)
        {
            pascal[i][0] = pascal[i][i] = 1;69
            for(int j=1; j<i; j++)
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
        }

        return (dfs(nums) - 1 + MOD ) % MOD;
    }
};