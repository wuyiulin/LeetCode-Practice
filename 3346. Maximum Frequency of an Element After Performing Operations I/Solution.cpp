class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int ops) 
  {
    int maxVal = *max_element(nums.begin(), nums.end());
    int cnt[maxVal], s[maxVal + 1];
    memset(cnt, 0, sizeof(cnt));
    memset(s, 0, sizeof(s));
    for (int num : nums) 
        cnt[num - 1]++;
    for (int i = 1; i <= maxVal; i++) 
        s[i] = s[i - 1] + cnt[i - 1];
    int res = 1;
    for (int i = 0; i < maxVal; i++) 
    {
      int l = max(0, i - k), r = min(maxVal - 1, i + k);
      res = max(res, min(s[r + 1] - s[l] - cnt[i], ops) + cnt[i]);
    }

    return res;
  }
};