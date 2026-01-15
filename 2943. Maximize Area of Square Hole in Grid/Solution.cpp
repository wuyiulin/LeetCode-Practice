class Solution {
private:
    int helper(vector<int> bars)
    {
        int curr = 1, res = 1, n = bars.size();
        sort(bars.begin(), bars.end());
        for(int i=1; i<n; i++)
        {
            if(bars[i] == bars[i - 1] + 1)
                curr++;
            else
                curr = 1;
            res = max(res, curr);
        }

        return res + 1;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        int hGap = helper(hBars), vGap = helper(vBars);
        int minGap = min(hGap, vGap);

        return minGap * minGap;
    }
};