class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        unordered_map<int, int> rec;
        int res = 0, n = nums.size();
        for(const int num : nums) rec[num]++;
        for(auto it = rec.begin(); it !=rec.end();)
        {
            if(--(it->second)) it++;
            else it = rec.erase(it);
        } 
        
        for(int i=0; i<n; i+=3)
        {
            if(rec.empty()) return res;
            for(int j=i; j<min(n, i+3); j++)
            {
                if(!rec.count(nums[j])) continue;
                if(!(--rec[nums[j]])) rec.erase(nums[j]);
            }
            res++;
        }
        
        return res;
    }
};

