class Solution {
    using LL = long long;
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        vector<LL> res(n, 0);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) 
            mp[nums[i]].push_back(i);

        for(auto& v : mp) 
        {
            vector<int>& indices = v.second;
            int m = indices.size();

            LL total = 0;
            for(int idx : indices) 
                total += idx;

            LL prefix = 0;
            for(int i = 0; i < m; i++) 
            {
                LL currIdx = indices[i];
                LL lc = i, rc = m - 1 - i;
                LL suffix = total - prefix - currIdx;

                res[currIdx] = (lc * currIdx - prefix) + (suffix - rc * currIdx);

                prefix += currIdx;
            }
        }

        return res;
    }
};