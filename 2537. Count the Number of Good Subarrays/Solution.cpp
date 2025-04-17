class Solution {
using LL = long long;
private:
    long long calPair(int x)
    {
        return x*(x-1)/2;
    }
public:
    long long countGood(vector<int>& nums, int k) 
    {
        LL res = 0;
        int n = nums.size();
        int l = 0, r = 0, status = 0, pre = 0, curr = 0;
        unordered_map<int, int> cnt;
        while(r<n)
        {            
            pre = calPair(cnt[nums[r]]);
            curr = calPair(++cnt[nums[r]]);
            status += (curr - pre);
            while(status >= k)
            {
                res += (n - r);
                pre = calPair(cnt[nums[l]]);
                curr = calPair(--cnt[nums[l]]);
                status += (curr - pre);
                l++;
            }
            r++;
        }

        return res;
    }
};

