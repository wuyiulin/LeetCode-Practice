class Solution 
{
private:
    int helper(int n)
    {
        if(n <= 1)
            return n;
        
        int highestBit = 0, curr = n;
        while(curr)
        {
            highestBit++;
            curr >>= 1;
        }

        int highestPower = 1 << (highestBit - 1);
        return ((1 << highestBit) - 1) - helper(n ^ highestPower);
    }

public:
    int minimumOneBitOperations(int n) 
    {
        return helper(n); 
    }
};
