struct VecComparator
{
    bool operator()(const vector<string>& a, const vector<string>& b)
    {
        int at = stoi(a[1]), bt = stoi(b[1]);
        if(at != bt)
            return at < bt;

        bool aOffline = (a[0] == "OFFLINE");
        bool bOffline = (b[0] == "OFFLINE");
        if(aOffline != bOffline)
            return aOffline;

        return false;
    }
};

vector<int> parseIDs(const string& s)
{
    vector<int> nums;
    istringstream iss(s);
    string token;
    while (iss >> token)
    {
        if (token.size() > 2 && token.substr(0,2) == "id")
        {
            int uid = stoi(token.substr(2));
            nums.push_back(uid);
        }
    }
    return nums;
}

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) 
    {
        vector<int> res(numberOfUsers, 0);
        vector<int> state(numberOfUsers, -1);

        sort(events.begin(), events.end(), VecComparator{});
        for(const auto& e : events)
        {
            int timestamp = stoi(e[1]);
            if(e[0] == "OFFLINE")
            {
                int uid = stoi(e[2]);
                state[uid] = timestamp + 60;
            }
            else
            {
                if(e[2] != "HERE" && e[2] != "ALL")
                {
                    vector<int> uids = parseIDs(e[2]);
                    for(const auto& uid : uids)
                            res[uid]++;
                }
                else
                {
                    for(int i=0; i<numberOfUsers; i++)
                    {
                        if(e[2] == "HERE")
                        {
                            if(timestamp >= state[i])
                                res[i]++;
                        }
                        else
                            res[i]++;
                    }
                }
            }
        }

        return res;
    }
};