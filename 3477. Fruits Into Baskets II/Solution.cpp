class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int fs = fruits.size(), bs = baskets.size();
        int cnt = 0;
        for(int i=0; i<fs; i++)
        {
            for(int j=0; j<bs; j++)
            {
                if(baskets[j] >= fruits[i])
                {
                    baskets[j] = 0;
                    cnt++;
                    break;
                }
            }
        }

        return fs - cnt;
    }
};