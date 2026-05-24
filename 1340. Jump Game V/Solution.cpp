class Solution {
private:
    int dfs(vector<int>& arr, int i, int d, int* dp)
    {
        if(dp[i])
            return dp[i];

        int curr = 1, n = arr.size();
        
        for(int j=i-1; j>=i-d && j>=0; j--)
        {
            if(arr[j] >= arr[i])
                break;
            curr = max(curr, dfs(arr, j, d, dp) + 1);
        }
        for(int j=i+1; j<=i+d && j<n; j++)
        {
            if(arr[j] >= arr[i])
                break;
            curr = max(curr, dfs(arr, j, d, dp) + 1);
        }

        dp[i] = curr;
        
        return dp[i]; 
    }
public:
    int maxJumps(vector<int>& arr, int d) 
    {
        int n = arr.size(), res = 1;
        int dp[n];
        fill(dp, dp + n, 0);
        for(int i=0; i<n; i++)
            res = max(res, dfs(arr, i, d, dp));

        return res;
    }   
};