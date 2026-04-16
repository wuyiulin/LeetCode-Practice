class Solution {
private:
    int dist(int l, int r, int n)
    {
        return (((r - l) + n) % n);
    }
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = nums.size(), qs = queries.size();
        unordered_map<int, vector<int>> mp;
        vector<int> res(qs, -1);
        for(int i=0; i<n; i++)
            mp[nums[i]].push_back(i);
        for(int i=0; i<qs; i++)
        {
            int q = queries[i];
            int val =  nums[q];
            auto it = lower_bound(mp[val].begin(), mp[val].end(), q);
            if(it == mp[val].end() || mp[val].size() == 1)
                continue;
            int l = it == mp[val].begin() ? mp[val].back() : *(it - 1);
            int r = (it + 1) == mp[val].end() ? mp[val].front() : *(it + 1);
            res[i] = min(dist(l, q, n), dist(q, r, n));
        }

        return res;
    }
};