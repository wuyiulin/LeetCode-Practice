class Solution {
private:
    bool vaild(string& s)
    {
        int res = 0;
        for(const char& c : s)
        {
            res += (c == '(' ? 1 : c == ')' ? -1 : 0);
            if(res < 0)
                return false;
        }

        return !res;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        bool f = false;
        vector<string> res = {};
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        int qs = q.size();
        while(!q.empty() && !f)
        {
            qs = q.size();
            for(int i=0; i<qs; i++)
            {
                string curr = q.front(); q.pop();
                int cs = curr.size();
                if(vaild(curr))
                {
                    res.push_back(curr);
                    f = true;
                }
                if(f)
                    continue;
                for(int j=0; j<cs; j++)
                {
                    if (curr[j] != '(' && curr[j] != ')') 
                        continue;
                    string next = curr.substr(0, j) + curr.substr(j + 1); 
                    if(visited.insert(next).second)
                        q.push(next);
                }
            }
        }

        return res;
    }
};