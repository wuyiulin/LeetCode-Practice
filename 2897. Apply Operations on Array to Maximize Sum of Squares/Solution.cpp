class Solution {
using LL = long long;
public:
    int maxSum(vector<int>& nums, int k) {
        LL mod = 1e9 + 7, res = 0;
        int cnt[32];
        memset(cnt, 0, sizeof(cnt));
        for(const auto num : nums)
        {
            int curr = num, idx = 0;
            while(curr)
            {
                cnt[idx++] += (curr & 1);
                curr >>= 1;
            }
        }
        for(int i=0; i<k; i++)
        {
            LL curr = 0;
            for(int j=31; j>=0; j--)
            {
                if(cnt[j])
                {
                    curr |= (1LL << j);
                    cnt[j]--;
                }
            }
            res += (int)((curr * curr) % mod);
            res %= mod;
        }

        return (int)res;
    }
};