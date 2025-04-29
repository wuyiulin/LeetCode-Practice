class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int maxNum = *max_element(nums.begin(), nums.end());
        int cnt = 0, r = 0, l = 0, n = nums.size();
        long long res = 0;
        while(r<n)
        {
            if(nums[r] == maxNum) cnt++;
            while(cnt==k)
            {
                if(nums[l] == maxNum) cnt--;
                l++;
            }
            res += l;
            r++;
        }

        return res;
    }
};