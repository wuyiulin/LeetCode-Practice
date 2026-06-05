class Solution {
using LL = long long;
private:
    vector<int> d;
    LL dp[30][16][11][11][2][2];
    LL solve(int pos, int sum, int pre2, int pre, bool small, bool nz)
    {
        if(pos == d.size())
            return sum;
        if(dp[pos][sum][pre2][pre][small][nz] != -1)
            return dp[pos][sum][pre2][pre][small][nz];
        
        int upbar = small ? 9 : d[pos];
        LL res = 0;
        for(int i=0; i<=upbar; i++)
        {
            bool nextSmall = (small || i<d[pos]);
            bool nextNZ = nz || i;
        
            if(nextNZ)
            {
                int nextPre2 = pre, nextPre = i;
                int nextSum = sum;
                if(pre2 != 10 && pre != 10)
                {
                    nextSum += (pre2 < pre && pre > i);
                    nextSum += (pre2 > pre && pre < i);
                }

                res += solve(pos + 1, nextSum, nextPre2, nextPre, nextSmall, nextNZ);
            }
            else
                res += solve(pos + 1, sum, pre2, pre, nextSmall, nextNZ);
            
            dp[pos][sum][pre2][pre][small][nz] = res;
        }

        return res;
    }

    LL count(LL num)
    {
        if(!num)
            return 0;
        d.clear();
        while(num)
        {
            d.push_back(num%10);
            num /= 10;
        }
        reverse(d.begin(), d.end());
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 10, 10, 0, 0);
    }
public:
    long long totalWaviness(long long num1, long long num2) 
    {
        return count(num2) - count(num1 - 1);    
    }
};