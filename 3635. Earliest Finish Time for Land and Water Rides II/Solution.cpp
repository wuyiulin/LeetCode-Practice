class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int m = landStartTime.size(), n = waterStartTime.size();
        int lt = INT_MAX, wt = INT_MAX, lw = INT_MAX, wl = INT_MAX, res = INT_MAX;
        for(int i=0; i<m; i++)
            lt = min(lt, landStartTime[i] + landDuration[i]);
        for(int j=0; j<n; j++)
            lw = min(lw, max(lt, waterStartTime[j]) + waterDuration[j]);
        for(int i=0; i<n; i++)
            wt = min(wt, waterStartTime[i] + waterDuration[i]);
        for(int j=0; j<m; j++)
            wl = min(wl, max(wt, landStartTime[j]) + landDuration[j]);

        res = min(lw, wl);

        return res;
    }
};