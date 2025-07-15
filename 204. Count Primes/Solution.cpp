class Solution {
public:
    int countPrimes(int n) 
    {
        int sqrtN = sqrt(n);
        vector<bool> table(n, false);
        for(int i=2; i<=sqrtN; i++)
        {
            if(table[i])
                continue;
            int p = 2;
            while(p*i < n)
            {
                table[p*i] = 1;
                p++;
            }
        }

        return max(0, n - accumulate(table.begin(), table.end(), 0) - 2);
    }
};