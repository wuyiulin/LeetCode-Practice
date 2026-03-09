class Solution {
using LL = long long;
LL dp0[201][201];
LL dp1[201][201];
LL pre1[201][201];
LL pre0[201][201];
LL mod = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        dp0[0][0] = 1;
        dp1[0][0] = 1;
        pre0[0][0] = 1;
        pre1[0][0] = 1;
        for(int i=0; i<=zero; i++)
        {
            for(int j=0; j<=one; j++)
            {
                if(!(i | j))
                    continue;
                LL tail0 = i - 1 < 0 ? 0 : pre1[j][i - 1], head0 = i - min(i, limit) - 1 < 0 ? 0 : pre1[j][i-min(i, limit) - 1];
                LL tail1 = j - 1 < 0 ? 0 : pre0[i][j - 1], head1 = j - min(j, limit) - 1 < 0 ? 0 : pre0[i][j-min(j, limit) - 1];
                dp0[i][j] = (tail0 - head0 + mod) % mod;
                dp1[i][j] = (tail1 - head1 + mod) % mod;

                pre0[i][j] = ((j < 1 ? 0 : pre0[i][j - 1]) + dp0[i][j]) % mod;
                pre1[j][i] = ((i < 1 ? 0 : pre1[j][i - 1]) + dp1[i][j]) % mod;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};