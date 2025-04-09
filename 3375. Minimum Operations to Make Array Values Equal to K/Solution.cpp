class Solution {
    public:
        int minOperations(vector<int>& nums, int k) 
        {
            if(*min_element(nums.begin(), nums.end()) < k) return -1;
            int n = nums.size();
            unordered_set<int> rec;
            for(const int& num : nums) rec.insert(num);
            rec.insert(k);
            
            return rec.size() - 1;
        }
    };
    
    