class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n = grid.size(), res = 0;
        vector<int> table(n, 0);
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(grid[i][j] == 1)
                {
                    table[i] = j;
                    break;
                }
            }
        }    

        for(int i=0; i<n; i++)
        {
            int j = i;
            while(j<n && table[j] > i)
                j++;
            
            if(j == n)
                return -1;
            
            while(j > i)
            {
                swap(table[j], table[j - 1]);
                res++;
                j--;
            }
        }

        return res;
    }
};