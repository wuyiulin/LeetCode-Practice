class Solution {
    public:
        int maxEvents(vector<vector<int>>& events) 
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            sort(events.begin(), events.end());
            int days = 0;
            for(const auto& e : events)
                days = max(days, e[1]);
            int i = 0, res = 0, n = events.size();
            for(int d = 1; d<=days; d++)
            {
                while(!pq.empty() && pq.top() < d)
                    pq.pop();
                while(i<n && events[i][0] == d)
                    pq.push(events[i++][1]);
                if(!pq.empty())
                {
                    pq.pop();
                    res++;
                }
            }
    
            return res;
        }
    };