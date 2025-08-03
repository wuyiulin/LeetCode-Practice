class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int n = max(fruits.back()[0], startPos + k), res = 0;
        vector<int> prefix(n+1, 0);
        for(const auto& fruit : fruits)
        {
            int idx = fruit[0], val = fruit[1];
            prefix[idx] = val;
        }
            
        for(int i=1; i<=n; i++)
            prefix[i] += prefix[i-1];

        for(int i=0; i<=k; i++)
        {
            int rightSteps = k - i;
            int rightPos = min(n, startPos + rightSteps);
            int leftSteps = i/2;
            int leftVal;
            leftVal = (startPos - leftSteps <= 0) ? 0 : prefix[startPos - leftSteps - 1];
            res = max(res, prefix[rightPos] - leftVal);
        }
        for(int i=0; i<=k; i++)
        {
            int rightSteps = i/2;
            int rightPos = min(n, startPos + rightSteps);
            int leftSteps = k - i;
            int leftVal;
            leftVal = (startPos - leftSteps <= 0) ? 0 : prefix[startPos - leftSteps - 1];
            res = max(res, prefix[rightPos] - leftVal);
        }

        return res;
    }
};