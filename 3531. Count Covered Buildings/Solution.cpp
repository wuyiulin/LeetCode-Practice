class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
    {
        unordered_map<int, vector<int>> x;
        unordered_map<int, vector<int>> y;
        for(const auto& b : buildings)
            {
                x[b[0]].push_back(b[1]);
                y[b[1]].push_back(b[0]);
            }
        for(auto& it : x) 
            sort(it.second.begin(), it.second.end());
        for(auto& it : y) 
            sort(it.second.begin(), it.second.end());
        int res = 0;
        for(const auto& b : buildings)
            {
                if(x[b[0]][0] != b[1] && x[b[0]].back() != b[1] && y[b[1]][0] != b[0] && y[b[1]].back() != b[0]) res++;
            }

        return res;
    }
};