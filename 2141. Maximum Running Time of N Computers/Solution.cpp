class Solution {
using LL = long long;
private:
    bool isVaild(vector<int>& batteries, LL tar, int n)
    {
        LL res = 0;
        for(int& battery : batteries)
            res += min(tar, 1LL*battery);
        
        return res >= tar*n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        LL sumB = accumulate(batteries.begin(), batteries.end(), 0LL);
        LL l = 1, r = sumB / n;
        while(l<r)
        {
            LL mid = (r - l) / 2 + l + 1;
            if(isVaild(batteries, mid, n))
                l = mid;
            else 
                r = mid - 1;
        }

        return l;
    }
};

