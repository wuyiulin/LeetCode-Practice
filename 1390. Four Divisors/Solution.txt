class Solution {
using LL = long long;
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        int res = 0;
        for(const auto& num : nums)
        {
            int cnt = 2, curr = num + 1;
            for(int i=2; i*i<=num; i++)
            {
                if(!(num % i))
                {
                    if(num != i * i)
                    {
                        curr = (curr + i + num / i);
                        cnt += 2;
                    }
                    else
                    {
                        cnt++;
                        break;
                    }
                        
                }
                if(cnt > 4)
                    break;
            }
            if(cnt == 4)
                res += curr;
        }
         
        return res;
    }
};