class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        unordered_map<int, vector<int>> x, y;
        int res = 0, n = points.size();

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            if (a[0] != b[0]) 
            {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });
        
        for(int i=0; i<n-1; i++)
        {
            int maxY = INT_MIN;
            for(int j=i+1; j<n; j++)
            {
                if (points[i][1] >= points[j][1] && points[j][1] > maxY)
                {
                    res++;
                    maxY = points[j][1];
                }
            }
        }

            return res;
    }
};