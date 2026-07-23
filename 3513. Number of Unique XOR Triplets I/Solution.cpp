class Solution {
private:
    int getHighest(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2) return n;

        return bit_width((unsigned)n);
    }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;

        return 1 << getHighest(nums);   
    }
};