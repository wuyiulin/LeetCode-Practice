class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        int n = s.size();
        string res = s;
        unordered_set<string> vis;
        queue<string> q;
        vis.insert(s);
        q.push(s);

        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            if (curr < res)
                res = curr;

            string cal = curr;
            for (int i = 1; i < n; i += 2)
            {
                int d = (cal[i] - '0' + a) % 10;
                cal[i] = char('0' + d);
            }
            if (!vis.count(cal))
            {
                vis.insert(cal);
                q.push(cal);
            }

            string rot = curr.substr(n - b) + curr.substr(0, n - b);
            if (!vis.count(rot))
            {
                vis.insert(rot);
                q.push(rot);
            }
        }

        return res;
    }
};
