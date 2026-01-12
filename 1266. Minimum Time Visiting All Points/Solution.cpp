class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int n = points.size(), res = 0;
        vector<int> pp = points[0];
        for(int i=1; i<n; i++)
        {
            int maxG = max(abs(pp[0] - points[i][0]), abs(pp[1] - points[i][1]));
            res += (maxG);
            pp = points[i];
        }

        return res;
    }
};