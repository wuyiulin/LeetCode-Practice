class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), curr = 0, res = INT_MAX;
        int dp[n], l = 0;
        fill(dp, dp + n, INT_MAX);
        for(int r=0; r<n; r++)
        {
            curr += arr[r];
            while(curr > target)
                curr -= arr[l++];
            int length = r - l + 1;
            if(curr == target)
            {
                if(l > 0 && dp[l - 1] != INT_MAX)
                    res = min(res, dp[l - 1] + length);
                dp[r] = length;
            }
            dp[r] = (!r) ? dp[r] : min(dp[r], dp[r - 1]);
        }

        return res == INT_MAX ? -1 : res;
    }
};