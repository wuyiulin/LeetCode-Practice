class Solution {
using LL = long long;
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        LL a[5] = {}, b[5] = {}, res[5] = {};
        LL *table = a, *next = b;
        for (int x : nums)
        {
            int curr = x % k;
            for (int r = 0; r < k; r++)
                next[(r * curr) % k] += table[r];
            next[curr]++;
            swap(table, next);                 
            memset(next, 0, sizeof(LL) * k);
            for (int r = 0; r < k; r++)
                res[r] += table[r];
        }
        return vector<LL>(res, res + k);
    }
};