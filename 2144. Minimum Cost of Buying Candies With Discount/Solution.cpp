class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        int n = cost.size(), res = 0;
        sort(cost.begin(), cost.end(), greater<>());
        for(int i=0; i<n; i=i+3)
        {
            for(int j=i; j<min(i+2, n); j++)
                res += cost[j];
        }

        return res; 
    }
};