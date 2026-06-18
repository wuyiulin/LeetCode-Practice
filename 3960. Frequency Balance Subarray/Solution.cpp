class Solution {
public:
    int getLength(vector<int>& nums) 
    {
        int n = nums.size(), res = 0;
        for(int i=0; i<n; i++)
        {
            unordered_map<int, int> mp;
            map<int, int> fs;
            for(int j=i; j<n; j++)
            {
                int curr = nums[j], cfs = 0;
                if(mp.count(curr))
                {
                    cfs = mp[curr];
                    fs[cfs]--;
                    if(fs[cfs] == 0)
                        fs.erase(cfs);
                }
                mp[curr]++;
                cfs += 1;
                fs[cfs]++;
                if(mp.size() == 1)
                {
                    res = max(res, j - i + 1);
                }
                else if(fs.size() == 2)
                {
                    if(fs.begin()->first*2 == fs.rbegin()->first)
                        res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};