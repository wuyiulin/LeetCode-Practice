using LL = long long;
const int MOD = 1e9 + 7;
const int M = 41;
LL fact[M];
LL invFact[M];

LL pow(LL x, int n)
{
    LL res = 1;
    while(n)
    {
        if(n % 2) res = (res * x) % MOD; 
        n /= 2;
        x = x * x % MOD;
    }

    return res;
}


class Solution {
private:
    static int dfs(int i, int left, int leftSum, const int table[10], vector<vector<vector<int>>>& memo)
    {
        if(i<0) return leftSum == 0;
        int& res = memo[i][left][leftSum];
        if(res != -1) return res;

        res = 0;
        int c = table[i] - (i ? table[i - 1] : 0);
        int right = table[i] - left;
        for(int k=max(c - right, 0); k<= min(c, left) && k*i<= leftSum; k++)
        {
            int r = dfs(i - 1, left - k, leftSum - k * i, table, memo);
            res = (res + r * invFact[k] % MOD * invFact[c - k]) % MOD;
        }

        return res;
    }
public:
    int countBalancedPermutations(string num) 
    {
        int table[10];
        memset(table, 0, sizeof(table));
        int Sum = 0, n = num.size();
        int half = n / 2;
        for(auto& c : num)
        {
            table[c - '0']++;
            Sum += c - '0';
        }
        if(Sum % 2) return 0;

        partial_sum(table, table+10, table);
        
        vector<vector<vector<int>>> memo(10, vector(half + 1, vector<int>(Sum / 2 + 1, -1))); 
        // init fact 
        fact[0] = 1;
        for(int i=1; i<M; i++)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[M - 1] = pow(fact[M - 1], MOD - 2);
        for(int i=M-1; i; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return fact[half] * fact[n - half] % MOD * dfs(9, half, Sum / 2, table, memo) % MOD;
    }
};