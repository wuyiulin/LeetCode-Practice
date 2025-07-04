class Solution {
using LL = long long;
public:
    char kthCharacter(long long k, vector<int>& operations) 
    {
        int p = 0;
        LL n = 1;
        while(n<k)
        {
            n *= 2;
            p++;
        }
        int shift = 0;
        p--;
        while(p>=0)
        {
            if(k > n/2)
            {
                k -= n/2;
                if(operations[p])
                    shift += operations[p];
            }
            n /= 2;
            p--;
        }

        return 'a' + (shift % 26);
    }
};

