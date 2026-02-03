class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int n = nums.size(), i = 1;
        bool p = false, q = false, t = true;
        while(i < n && nums[i - 1] < nums[i])
            i++;
        if(i == 1)
            return false;
        while(i < n && nums[i - 1] > nums[i])
            i++;
        if(i<=2 || i==n)
            return false;
        while(i < n && nums[i - 1] < nums[i])
            i++;
        if(i<=3)
            return false;
        return i == n;
    }
};