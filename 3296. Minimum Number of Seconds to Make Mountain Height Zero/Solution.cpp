class Solution {
using LL = long long;
private:
    bool helper(int mountainHeight, LL time, vector<int>& workerTimes)
    {
        for(const auto& wt : workerTimes)
        {
            // int l = 0;
            // while(time >= ct)
            //     ct += (wt * (++l));
            // mountainHeight -= (l - 1);
            LL ct = (sqrt(1 + 8.0 * time / wt) - 1) / 2;
            mountainHeight -= ct;
            if(mountainHeight <= 0)
                return true;
        }

        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) 
    {
        LL maxmal = 1LL * mountainHeight * (*max_element(workerTimes.begin(), workerTimes.end()));
        LL lo = 1, hi = maxmal >= sqrt(LLONG_MAX) ? LLONG_MAX : 1LL * maxmal * (maxmal + 1) / 2;
        while(lo < hi)
        {
            LL mid = lo + (hi - lo) / 2;
            if(helper(mountainHeight, mid, workerTimes))
                hi = mid;
            else
                lo = mid + 1;
        }

        return hi;
    }
};