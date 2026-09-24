class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int digitSum = 0, curr = nums[i];
            while(curr && digitSum<=i)
            {
                digitSum += (curr % 10);
                curr /= 10;
            }
            if(digitSum == i)
                return i;
        }

        return -1;
    }
};