class Solution {
using LL = long long;
private:
    LL count(LL m, const vector<int>& coins)
    {
        LL cnt = 0;
        int n = coins.size();
        for(int i=1; i<(1<<n); i++)
        {
            LL lcm_val = 1;
            int bits = 0;
            bool f = false;
            for(int j=0; j<n; j++)
            {
                if((i>>j) & 1)
                {
                    bits++;
                    lcm_val = lcm(lcm_val, coins[j]);
                    if(lcm_val > m)
                    {
                        f = true;
                        break;
                    }
                }
            }
            if(f)
                continue;
            if(bits % 2)
                cnt += (m / lcm_val);
            else
                cnt -= (m / lcm_val);
        }

        return cnt;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        LL l = 1, r = 8e10, res = r;
        while(l <= r)
        {
            LL mid = l + (r - l) / 2;
            if(count(mid, coins) >= k)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return res;
    }
};