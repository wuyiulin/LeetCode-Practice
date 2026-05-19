class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size(), n = nums2.size(), j = 0;
        for(int i=0; i<m; i++)
        {
            while(j < n && nums1[i] >= nums2[j])
            {
                if(nums1[i] == nums2[j])
                    return nums1[i];
                j++;
            }
        }

        return -1;
    }
};