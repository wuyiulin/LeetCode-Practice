class Solution 
{
using LL = long long;

private:
    bool helper(vector<LL> power, LL k, int r, LL target) 
    {
        int n = power.size();
        vector<LL> diff(n, 0); 
        LL added = 0;              
        int span = 2 * r + 1;      

        for (int i = 0; i < n; ++i) 
        {
            added += diff[i];                  
            LL curr = power[i] + added;        
            if (curr < target) 
            {
                LL need = target - curr;
                k -= need;
                if (k < 0) 
                    return false;
                added += need;                 
                int endPos = i + span;        
                if (endPos < n)             
                    diff[endPos] -= need;
            }
        }
        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) 
    {
        int n = stations.size();
        vector<LL> power(n, 0);

        LL curr = 0;
        for (int j = 0; j <= min(n - 1, r); ++j) 
        {
            curr += stations[j];
        }
        for (int i = 0; i < n; ++i) 
        {
            power[i] = curr;
            int removeIdx = i - r;
            int addIdx = i + r + 1;
            if (removeIdx >= 0) 
            {
                curr -= stations[removeIdx];
            }
            if (addIdx < n) 
            {
                curr += stations[addIdx];
            }
        }

        LL lo = *min_element(power.begin(), power.end());
        LL hi = *max_element(power.begin(), power.end()) + k;
        while (lo < hi) 
        {
            LL mid = lo + (hi - lo + 1) / 2;
            if (helper(power, k, r, mid)) 
            {
                lo = mid;
            } 
            else 
            {
                hi = mid - 1;
            }
        }
        return lo;
    }
};