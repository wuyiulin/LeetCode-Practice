class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) 
    {
        int res = numBottles, empty = 0;
        while(numBottles)
        {
            int next = 0;
            numBottles += empty;
            empty = 0;
            while(numBottles >= numExchange)
            {
                numBottles -= numExchange;
                next++;
                numExchange++;
            }
            empty += numBottles;
            numBottles = next;
            res += next;
        }

        return res;
    }
};

