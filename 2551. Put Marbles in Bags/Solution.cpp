class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        if(k >= n) return 0;
        vector<int> rec(n - 1, 0);
        for(int i=1; i<n; i++) rec[i-1] = weights[i - 1] + weights[i];
        
        sort(rec.begin(), rec.end());
        long long res = accumulate(rec.end() - (k - 1), rec.end(), 0*1LL) - accumulate(rec.begin(), rec.begin() + k - 1, 0*1LL);

        return res;
    }
};

