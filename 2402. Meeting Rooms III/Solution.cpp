using PIL = pair<int, long long>;
struct CMP
{
    bool operator()(const PIL& a, const PIL& b) const
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        int table[n];
        memset(table, 0, sizeof(table));
        sort(meetings.begin(), meetings.end());
        priority_queue<PIL, vector<PIL>, CMP> work;
        priority_queue<int, vector<int>, greater<int>> empty;
        
        for(auto& m : meetings)
            m[1] -= m[0];

        for(int i=0; i<n; i++)
            empty.push({i});

        for(const auto& m : meetings)
        {
            long long startTime = 1LL * m[0];
            while(!work.empty() && work.top().second <= startTime)
            {
                PIL w = work.top(); work.pop();
                empty.push(w.first);    
            }
            int curr = -1;
            if(!empty.empty())
            {
                curr = empty.top(); empty.pop();
            }
            else
            {
                startTime = work.top().second;
                PIL w = work.top(); work.pop();
                empty.push(w.first);    
                curr = empty.top(); empty.pop();
            }
            table[curr]++;
            work.push({curr, 1LL * startTime + m[1]});
        }

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            if(table[i] > table[res])
            {
                res = i;
            }
        }

        return res;
    }
};