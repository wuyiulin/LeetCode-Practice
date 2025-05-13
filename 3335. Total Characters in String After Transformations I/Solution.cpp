class Solution {
using LL = long long;
using mat = vector<vector<LL>>;
private:
    int MOD = 1e9 + 7;
    mat mulMat(const mat& A, const mat& B)
    {
        mat res(26, vector<LL>(26, 0));
        for (int i = 0; i < 26; i++)
        {
            for (int k = 0; k < 26; k++)
            {
                for (int j = 0; j < 26; j++)
                {
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    mat identity(int n)
    {
        mat res(n, vector<LL>(n, 0));
        for(int i=0; i<n; i++) res[i][i] = 1;

        return res;
    }

    mat powMat(auto& T, int p)
    {
        int n = T.size();
        mat res = identity(n);
        while(p)
        {
            if(p % 2) res = mulMat(res, T);
            T = mulMat(T, T);
            p /= 2;
        }

        return res;
    }
public:
    int lengthAfterTransformations(string s, int t) 
    {
        vector<int> table(26, 0);
        for(const char& c : s) table[c - 'a']++;

        mat T(26, vector<LL>(26, 0));
        for (int i = 0; i < 25; i++)　T[i + 1][i] = 1;
        T[0][25] = 1;
        T[1][25] = 1;
        T = powMat(T, t);
        int res = 0;
        for(int i=0; i<26; i++)
        {
            LL curr = 0;
            for(int j=0; j<26; j++)
            {
                curr = (curr + (T[i][j] % MOD) * table[j] % MOD) % MOD;
            }
             res = (res * 1LL + (curr % MOD)) % MOD; 
        }

        return res;
    }
};