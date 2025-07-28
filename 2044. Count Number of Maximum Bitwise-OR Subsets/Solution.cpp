class Solution {
int n;
int cnt = 0, maxNum = 0;
private:
    void dp(vector<int>& nums, int idx, int curr)
    {
        if(idx == n)
        {
            if(curr>maxNum)
            {
                cnt = 1;
                maxNum = curr;
            }
            else if(curr == maxNum)
                cnt++;
            return;
        }
        dp(nums, idx+1, curr);
        dp(nums, idx+1, curr|nums[idx]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        n = nums.size();
        dp(nums, 0, 0);

        return cnt;
    }
};