class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        int red = 0;
        for(int i=1; i<=k; i++)
        {
            red = (red * 10 + 1) % k;
            if(!red)
                return i;
        }

        return -1;
    }
};