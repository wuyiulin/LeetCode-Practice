class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        int n = classes.size();
        double res = 0.0;
        priority_queue<pair<double, int>> pq;
        for(int i=0; i<n; i++)
            pq.push({(1.0 * classes[i][1] - classes[i][0]) / (1.0 * classes[i][1] * (classes[i][1] + 1)), i});
        while(extraStudents)
        {
            auto p = pq.top();
            classes[p.second][0]++;
            classes[p.second][1]++;
            pq.pop();
            pq.push({(1.0 * classes[p.second][1] - classes[p.second][0]) / (1.0 * classes[p.second][1] * (classes[p.second][1] + 1)), p.second});
            extraStudents--;
        }

        for(int i=0; i<n; i++)
            res += (1.0 * classes[i][0] / classes[i][1]);

        return res / n;
    }
};