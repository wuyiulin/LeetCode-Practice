class Solution {
using LL = long long;
const LL mod = 1e9 + 7;
private:
LL power(long long base, long long exp) 
{
    long long res = 1;
    base %= mod;
    while (exp > 0) 
    {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

LL modInv(long long n) 
{
    return power(n, mod - 2);
}
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int res = 0, n = nums.size();

        unordered_map<int, unordered_map<int, int>> diff;
        for(auto& q : queries)
        {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            int end = r + k - ((r - l) % k);
            int rem = l % k;
            if(diff[k].find(l) == diff[k].end())
                diff[k][l] = 1;
            diff[k][l] = (1LL * diff[k][l] * v) % mod;

            if(end < n)
            {
                if(!diff[k].count(end))
                    diff[k][end] = 1;
                diff[k][end] = (int)((1LL * diff[k][end] * modInv(v)) % mod);
            }
        }

        for (auto& [k, points] : diff) 
        {
            unordered_set<int> affected_rems;
            for (auto& [idx, val] : points) 
            {
                affected_rems.insert(idx % k);
            }

            for (int rem : affected_rems) 
            {
                long long cur = 1;
                for (int i = rem; i < n; i += k) 
                {
                    auto it = points.find(i);
                    if (it != points.end()) 
                    {
                        cur = (cur * it->second) % mod;
                    }
                    if (cur != 1) 
                    {
                        nums[i] = (1LL * nums[i] * cur) % mod;
                    }
                }
            }
        }

        for(const auto& num : nums)
            res ^= num;

        return res;
    }
};