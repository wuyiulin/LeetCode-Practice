class Solution {
private:
    int cntWindows(vector<int>& nums, int x, int k)
    {
        int cnt = 0, n = nums.size();
        for(int i=0; i+k<=n; i++)
        {
            for(int j=i; j<i+k; j++)
            {
                if(nums[j] == x)
                {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) 
        {
            int res = -1;
            for (int i = 0; i < n; i++)
                if (count(nums.begin(), nums.end(), nums[i]) == 1)
                    res = max(res, nums[i]);

            return res;
        }

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        int res = -1;
        if (cntWindows(nums, nums[0], k) == 1) res = max(res, nums[0]);
        if (cntWindows(nums, nums[n - 1], k) == 1) res = max(res, nums[n - 1]);
        
        return res;
    }
};