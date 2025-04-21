class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) 
    {
        int gap = upper - lower;
        long long dLo = 0, dUp = 0, prefix = 0;
        for(const auto& d : diff)
        {
            prefix += d;
            dLo = min(dLo, prefix);
            dUp = max(dUp, prefix);
        }
        int calGap = dUp - dLo;

        if(gap < calGap) return 0;

        return gap - calGap + 1;
    }
};

