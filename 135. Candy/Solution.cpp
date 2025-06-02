class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int> table(n, 1);
        
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                table[i] = table[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                table[i] = max(table[i], table[i + 1] + 1);
        }

        return accumulate(table.begin(), table.end(), 0);
    }
};