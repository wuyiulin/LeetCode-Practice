class Solution {
private:
    bool dfs(vector<int>& nums, vector<int>& lens, vector<int>& res, vector<int>& curr, unordered_map<int, unordered_set<int>>& vis, vector<int> pow10, int k, int currMod, int mask) 
    {
        if(!res.empty()) return true;
        if(vis.count(mask) && vis[mask].count(currMod)) return false;
        vis[mask].insert(currMod);

        if(curr.size() == nums.size()) 
        {
            if(currMod == 0) 
            {
                res = curr;
                return true;
            }
            return false;
        }

        for(int i = 0; i < nums.size(); i++) 
        {
            if(mask & (1 << i)) continue;

            curr.push_back(nums[i]);
            int newMask = mask | (1 << i);
            int newMod = (currMod * pow10[lens[i]] + nums[i]) % k;

            if(dfs(nums, lens, res, curr, vis, pow10, k, newMod, newMask)) 
                return true;

            curr.pop_back();
        }
        return false;
    }

public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, unordered_set<int>> vis;
        
        vector<int> pow10(7, 1);
        for(int i = 1; i < 7; i++) 
            pow10[i] = (pow10[i - 1] * 10) % k;
        
        vector<int> res, lens(n, 0);
        vector<int> curr;


        for(int i = 0; i < n; i++) 
            lens[i] = to_string(nums[i]).size();
        
        dfs(nums, lens, res, curr, vis, pow10, k, 0, 0);
        
        return res;
    }
};