class Solution {
using LL = long long;
private:
long long fastPow(long long base, int exp) 
    {
        long long res = 1;
        while (exp > 0) 
        {
            if (exp % 2 == 1) res *= base;
            base *= base;
            exp /= 2;
        }

        return res;
    }
    LL DFS(string tar, string s, int limit, int idx, bool carry)
    {
        LL res = 0;
        if(tar.size() < s.size()) return 0;
        else if(tar.size() == s.size() || tar.size() - s.size() <= idx) return (carry || stoll(tar.substr(idx)) >= stoll(s));
        int d = tar.size() - s.size() - idx - 1; 
        if(carry)
        {
            res = fastPow(limit + 1, d + 1);
        }
        else
        {
            for(int i=0; i<=min(limit, tar[idx] - '0'); i++)
            {
                if(i == tar[idx] - '0') res += DFS(tar, s, limit, idx + 1, false);
                else res += DFS(tar, s, limit, idx + 1, true);
            }
        }

        return res;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) 
    {
        return DFS(to_string(finish), s, limit, 0, false) - DFS(to_string(start-1), s, limit, 0, false);    
    }
};