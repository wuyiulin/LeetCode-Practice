class Solution {
private:
    int check(vector<int>& nums, int z)
    {
        int n = nums.size();
        int r = (z + 1 + n) % n, status = -2, cnt = n - 1; // -1 逆方向, 0 無序, 1 正方向
        if(nums[r] != nums[z] + 1)
            status = -1;
        else
            status = 1;
        r = (z + status + n) % n;
        while(cnt--)
        {
            if(nums[r] != nums[z] + 1)
            {
                status = 0;
                return status;
            }
            z = r;
            r = (z + 1 * status + n) % n;
        }

        return status;
    }
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size(), zIdx = -1, dir = -2, res = 0;
        for(int i=0; i<n; i++)
        {
            if(!nums[i])
            {
                zIdx = i;
                break;
            }
        }
        dir = check(nums, zIdx);
        if(!dir)
            return -1;
        else if(dir == 1)
        {
            res = min(zIdx, n - zIdx + 2);
        }
        else
        {
            res = 1;
            // 先轉後算
            int rIdx = (n - 1 - zIdx);
            // 先算後轉
            int lIdx = (zIdx + 1) % n;
            res += min(rIdx, lIdx);
        }

        return n == 1 ? 0 : res;
    }
};