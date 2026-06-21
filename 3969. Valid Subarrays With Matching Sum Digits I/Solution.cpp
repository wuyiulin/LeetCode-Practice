class Solution {
using LL = long long;
private:
    int helper(LL num)
    {
        while(num >= 10)
            num/=10;

        return num;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) 
    {
        int n = nums.size() + 1, res = 0;
        vector<LL> prefix(n, 0);
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                LL curr = prefix[j] - prefix[i];
                if(helper(curr) == x && curr%10 == x)
                    res ++;
            }
        }

        return res;
    }
};