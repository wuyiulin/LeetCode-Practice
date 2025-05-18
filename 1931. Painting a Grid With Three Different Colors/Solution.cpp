class Solution {
int MOD = 1e9 + 7;
private:
    bool isVaild(int a, int m)
    {
        int pre = -1;
        for (int i = 0; i < m; ++i)
        {
            int cur = a % 3;
            if (cur == pre) return false;
            pre = cur;
            a /= 3;
        }

        return true;
    }

    bool isMatch(int a, int b, int m)
    {
        for (int i = 0; i < m; ++i)
        {
            if (a % 3 == b % 3) return false;
            a /= 3;
            b /= 3;
        }

        return true;
    }

public:
    int colorTheGrid(int m, int n) 
    {
        vector<int> vaild;
        int maxState = pow(3, m);
        for(int i=0; i<maxState; i++)
        {
            if(isVaild(i, m)) vaild.push_back(i);
        }
        int vs = vaild.size();
        vector<vector<int>> trans(vs);
        for(int i=0; i<vs; i++)
        {
            for(int j=i+1; j<vs; j++)
            {
                if(isMatch(vaild[i], vaild[j], m))
                {
                    trans[i].push_back(j);
                    trans[j].push_back(i);
                }
            }
        }

        vector<int> dp(vs, 1);
        while(--n)
        {
            vector<int> nextDp(vs, 0);
            for(int i=0; i<vs; i++)
            {
                for(const auto& j : trans[i])
                {
                    nextDp[j] = (nextDp[j] + dp[i]) % MOD;
                }
            }
            dp = nextDp;
        }

        int res = 0;
        for(const auto& cnt : dp) res = (res + cnt) % MOD;

        return res;
    }
};