class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        
        long long prefixMax = nums[0];
        long long prefixMin = nums[0];
        
        long long res = LLONG_MIN;
        
        for(int i = m-1; i < n; i++) 
        {
            prefixMax = max(nums[i - m + 1] * 1LL, prefixMax);
            prefixMin = min(nums[i - m + 1] * 1LL, prefixMin);

            long long product1 = prefixMax * nums[i];
            long long product2 = prefixMin * nums[i];
            
            res = max(res, max(product1, product2));
        }
        
        return res;
    }
};

