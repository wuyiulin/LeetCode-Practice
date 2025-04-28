class Solution {
    using LL = long long;
    public:
        long long countSubarrays(vector<int>& nums, long long k) 
        {
            int n = nums.size();
            LL res = 0, curr = 0;
            int r = 0, l = 0;
            while(r<n)
            {
                curr += nums[r];
                while(1LL * (r + 1 - l) * curr >= k)
                {
                    curr -= nums[l];
                    l++;
                }
    
                res += (r + 1 - l);
                r++;
            }
    
            return res;
        }
    };