class Solution {
public:
    int furthestDistanceFromOrigin(string moves) 
    {
        int curr = 0, var = 0;
        for(const char& d : moves)
        {
            curr = d == 'L' ? curr - 1 : d == 'R' ? curr + 1 : curr;
            var = d == '_' ? var + 1 : var;
        }

        return abs(curr) + var;
    }
};