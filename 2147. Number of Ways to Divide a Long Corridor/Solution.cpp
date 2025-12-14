class Solution {
using LL = long long;
public:
    int numberOfWays(string corridor) 
    {
        int set_cnt = 0, plant_cnt = 0, res = 0;
        const LL mod = 1e9 + 7;
        for(const auto& c : corridor)
        {
            if(c == 'P')
            {
                if(!set_cnt && res)
                    plant_cnt++;
            }
            else
            {
                set_cnt++;
            }
                   
            if(set_cnt == 2)
            {
                if(!res)
                {
                    res = 1;
                }
                else
                {
                    LL tar = (1LL * res * (plant_cnt + 1)) % mod; 
                    res = tar % mod; 
                }
                    
                set_cnt = 0;
                plant_cnt = 0;
            }
        }


        return set_cnt ? 0 : res;
    }
};