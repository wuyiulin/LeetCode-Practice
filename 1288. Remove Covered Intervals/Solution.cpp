class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0]<b[0])
            return true;
        else if(a[0] == b[0])
            return a[1] > b[1];
        
        return false;
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size(), cnt = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i=0; i<n; i++)
        {
            if(intervals[i][0] == -1)
                continue;
            for(int j=i+1; j<n; j++)
            {
                
                if(intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1])
                {
                    intervals[j] = {-1, -1};
                    cnt++;
                }
            }
        }

        return n - cnt;
    }
};