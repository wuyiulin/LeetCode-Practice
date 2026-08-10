class Solution {
private:
    bool helper(vector<bool>& dp, int stones)
    {
        if(stones <= 0)
            return false;
        if(dp[stones] != false)
            return true;
        for(int i=1; i*i<=stones; i++)
        {
            if(!helper(dp, stones - i*i))
                return dp[stones] = true;
        }

        return dp[stones] = false;
    }
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        
        return helper(dp, n);
    }
};