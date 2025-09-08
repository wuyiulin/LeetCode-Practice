class Solution {
using LL = long long;
private:
    bool isVaild(LL n, int t)
    {
        LL p = 0, m = n;
        while(m>0)
        {
            if(m&1)
                p++;
            m >>= 1;
        }
        
        return t >= p && t <= n;
    }
public:
    int makeTheIntegerZero(int num1, int num2) 
    {
        num1 *= 1LL;
        for(LL t=1; t<=34; t++)
        {
            LL x = num1 - t * num2;
            if(x < 0)
                continue; 
            if(isVaild(x, t))
                return (int)t;
        }

        return -1;
    }
};