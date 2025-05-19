class Solution {
private:
    static int calVal(int x)
    {
        int val = 0;
        while (x)
        {
            val += x % 10;
            x /= 10;
        }

        return val;
    }

    static bool cmp(int a, int b)
    {
        int va = calVal(a), vb = calVal(b);

        return (va == vb) ? a < b : va < vb;
    }

public:
    int minSwaps(std::vector<int>& nums)
    {
        int n = nums.size(), res = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), cmp);
        unordered_map<int, int> table;
        for(int i=0; i<n; i++)
            table[sorted[i]] = i;
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++)
        {
            if(vis[i] || table[nums[i]] == i) 
                continue;
            
            int cs = 0;
            int j = i;
            while(!vis[j])
            {
                vis[j] = true;
                j = table[nums[j]];
                cs++;
            }

            res += (cs - 1);
        }

        return res;
    }
};