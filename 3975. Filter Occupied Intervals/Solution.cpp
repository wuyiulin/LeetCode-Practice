class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& ois, int freeStart, int freeEnd) 
    {
        int n = ois.size();
        sort(ois.begin(), ois.end());
        
        vector<vector<int>> tmp;
        for(auto& interval : ois)
        {
            if(tmp.empty() || tmp.back()[1] < interval[0] - 1)
                tmp.push_back(interval);
            else
                tmp.back()[1] = max(tmp.back()[1], interval[1]);
        }
        ois = tmp;
        tmp = {};

        for(auto& o : ois)
        {
            bool si = o[0] >= freeStart, ei = o[1] <= freeEnd, 
                 overlap = freeStart > o[0] && freeEnd < o[1];
            
            if(si && ei)
                o = {-1, -1};
            else if(si && o[0] <= freeEnd)
                o[0] = freeEnd + 1;
            else if(freeStart <= o[1] && ei)
                o[1] = freeStart - 1;
            else if(overlap)
            {
                tmp.push_back({freeEnd + 1, o[1]});
                o[1] = freeStart - 1;
            }
        }
        
        for(auto& v : tmp)
            ois.push_back(v);
        
        for(auto it = ois.begin(); it != ois.end();)
        {
            if((*it)[0] == -1)
                it = ois.erase(it);
            else
                it++;
        }
        
        sort(ois.begin(), ois.end());
        return ois;
    }
};