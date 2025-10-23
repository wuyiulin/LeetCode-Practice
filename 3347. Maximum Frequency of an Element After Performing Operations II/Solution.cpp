class Solution {
using LL = long long;
public:
    int maxFrequency(vector<int>& nums, int k, int ops) 
    {
        vector<LL> table(nums.begin(), nums.end());
        if(k)
        {
            for(int num : nums)
            {
                table.push_back(num + k);
                table.push_back(num - k);
            }
        }
        sort(table.begin(), table.end());
        table.erase(unique(table.begin(), table.end()), table.end());
        int n = table.size();
        unordered_map<int, int> mid;
        for(int i=0; i<n; i++)
            mid[table[i]] = i;
        int cnt[n], s[n + 1], res = 1;
        memset(cnt, 0, sizeof(cnt));
        memset(s, 0, sizeof(s));
        for(int num : nums)
            cnt[mid[num]]++;
        for(int i=1; i<= n; i++)
            s[i] = s[i - 1] + cnt[i - 1];
        for(int i=0; i<n; i++)
        {
            int l = lower_bound(table.begin(), table.end(), table[i] - k) - table.begin();
            int r = upper_bound(table.begin(), table.end(), table[i] + k) - table.begin();
            res = max(res, min(s[r] - s[l] - cnt[i], ops) + cnt[i]);
        }

        return res;
    }
};