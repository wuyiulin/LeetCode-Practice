class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        int rMax = *max_element(rains.begin(), rains.end());
        int n = rains.size();
        unordered_map<int, int> table;
        set<int> capacity;
        for(const auto& r : rains)
            table[r] = -1;
        for(int i=0; i<n; i++)
        {
            int r = rains[i];
            if(r)
            {
                int last = table[r];
                if(last == -1)
                {
                    table[r] = i;
                    rains[i] = -1;
                }
                else
                {
                    auto it = capacity.upper_bound(last);
                    if(it == capacity.end())
                        return {};
                    else
                    {
                        table[r] = i;
                        rains[*it] = r;
                        capacity.erase(it);
                        rains[i] = -1;
                    }
                }
            }
            else
            {
                capacity.insert(i);
            }
        }

        for(const auto& c : capacity)
            rains[c] = rMax;

        return rains;
    }
};

