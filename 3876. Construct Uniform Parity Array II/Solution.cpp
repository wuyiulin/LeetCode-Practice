class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minE = INT_MAX, minO = INT_MAX;
        bool odd = true, even = true;
        for(const auto num : nums1)
        {
            if(num % 2)
            {
                even = false;
                minO = min(minO, num);
            }
            else
            {
                odd = false;
                minE = min(minE, num);
            }
        }
        if(odd || even)
            return true;

        return minE > minO;
    }
};