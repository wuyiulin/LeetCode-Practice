class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int k=1; k<=n; k++)
        {
            if(n % k)
                continue;
            bool f = true;
            int preMaxG = INT_MIN;
            for(int i=0; i<n && f; i=i+k)
            {
                int preMaxL = INT_MIN, preMinL = INT_MAX, cntLocal = 0;
                for(int j=i; j<i+k; j++)
                {
                    if(nums[j - 1 >= i ? j - 1 : j + k - 1] > nums[j])
                        cntLocal++;
                    if(cntLocal > 1)
                    {
                        f = false;
                        break;
                    }
                    preMaxL = max(preMaxL, nums[j]);
                    preMinL = min(preMinL, nums[j]);
                }
                if(preMaxG > preMinL)
                {
                    f = false;
                    break;
                }
                preMaxG = preMaxL;
            }
            if(f)
                res += k;
        }

        return res;
    }
};