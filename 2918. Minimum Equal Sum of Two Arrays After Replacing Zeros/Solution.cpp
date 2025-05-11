class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int s1 = nums1.size(), s2 = nums2.size();
        long long Sum1 = 0, Sum2 = 0, zn1 = 0, zn2 = 0;
        for(const auto& num : nums1)
        {
            if(num) Sum1 += num;
            else zn1++;
        }
        for(const auto& num : nums2)
        {
            if(num) Sum2 += num;
            else zn2++;
        }
        
        if((Sum1 + zn1 > Sum2 && !zn2)  || (Sum1 < Sum2 + zn2 && !zn1)) return -1;

        return max(Sum1 + zn1, Sum2 + zn2);
    }
};