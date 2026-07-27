class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s, cnt;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                s.insert(nums[i]^nums[j]);
        
        for(int i=0; i<n; i++)
            for(auto& t : s)
                cnt.insert(nums[i]^t);

        return cnt.size();
    }
};