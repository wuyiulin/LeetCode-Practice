class Solution {
private:
    int isVaild(vector<int>& nums, const int& n, const int& diff)
    {
        int cnt = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] - nums[i - 1] <= diff)
            {
                cnt++;
                i++;
            }
        }

        return cnt;
    }
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), diff = 1e9;
        int l = 0, r = 1e9;
        while(l<=r)
        {
            int mid = l + (r - l) / 2;
            int cnt = isVaild(nums, n, mid);
            if(cnt >= p)
            {
                diff = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return diff;
    }
};