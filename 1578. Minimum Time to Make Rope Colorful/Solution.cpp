class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n = colors.size(), res = 0;
        for(int i=1; i<n; i++)
        {
            if(colors[i - 1] == colors[i])
            {
                char color = colors[i - 1];
                int maxVal = INT_MIN, j = i - 1;
                for(; colors[j]==color && j<n; j++)
                {
                    res += neededTime[j];
                    maxVal = max(maxVal, neededTime[j]);
                }
                res -= maxVal;
                i = j - 1;
            }
        }

        return res;
    }
};