class Solution {
using LL = long long;
static const int MOD = 1e9 + 7;

private:
    void matmul(vector<vector<LL>>& A, vector<vector<LL>>& B, vector<vector<LL>>& C, int n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                C[i][j] = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
    }
    
    void matPow(vector<vector<LL>>& T, vector<vector<LL>>& res, LL p, int n)
    {
        for(int i = 0; i < n; i++)
            res[i][i] = 1;
        
        vector<vector<LL>> tmp(n, vector<LL>(n, 0));
        
        while(p)
        {
            if(p & 1)
            {
                matmul(res, T, tmp, n);
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        res[i][j] = tmp[i][j];
            }
            matmul(T, T, tmp, n);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    T[i][j] = tmp[i][j];
            p >>= 1;
        }
    }

public:
    int zigZagArrays(int n, long long l, long long r)
    {
        int m = r - l + 1;
        vector<LL> dp(2 * m, 0);
        
        for(int i = 0; i < m; i++)
        {
            dp[2 * i] = m - 1 - i;      // 下降
            dp[2 * i + 1] = i;          // 上升
        }
        
        if(n == 2)
        {
            LL res = 0;
            for(LL d : dp)
                res = (res + d) % MOD;
            return res;
        }
        
        vector<vector<LL>> T(2 * m, vector<LL>(2 * m, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < i; j++)
                T[2 * i + 1][2 * j] = 1;
            for(int j = i + 1; j < m; j++)
                T[2 * i][2 * j + 1] = 1;
        }
        
        vector<vector<LL>> TP(2 * m, vector<LL>(2 * m, 0));
        matPow(T, TP, n - 2, 2 * m);
        
        LL res = 0;
        for(int i = 0; i < 2 * m; i++)
        {
            for(int j = 0; j < 2 * m; j++)
            {
                res = (res + TP[i][j] * dp[j]) % MOD;
            }
        }
        
        return res;
    }
};