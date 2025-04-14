class Solution {
private:
    bool isNum(char& c)
    {
        return c >= '0' && c <= '9';
    }
    bool isLetter(char& c)
    {
        return c >= 'a' && c <= 'z';
    }
public:
    string decodeString(string s) 
    {
        int n = s.size();
        string res = "";
        stack<int> sti;
        stack<string> sts;
        int idx = 0;
        while(idx < n)
        {
            int next = idx;
            if(isNum(s[idx]))
            {
                while(next < n && isNum(s[next]))
                {
                    next++;
                }
                sti.push(stoi(s.substr(idx, next - idx)));
                idx = next;
            }
            else if (isLetter(s[idx]))
            {
                while(next < n && isLetter(s[next]))
                {
                    next++;
                }
                string letters = s.substr(idx, next - idx);
                if(sti.empty())
                {
                    res += letters;
                }
                else
                {
                    string tmp = sts.top(); sts.pop();
                    tmp += letters;
                    sts.push(tmp);
                }
                idx = next;
            }
            else if(s[idx] == '[')
            {
                sts.push("");
                idx++;
            }
            else
            {
                int prod = sti.top(); sti.pop();
                string candidate = sts.top(); sts.pop();
                string expand = "";
                for(int i=0; i<prod; i++) expand += candidate;
                if(sti.empty()) res += expand;
                else
                {
                    string top = sts.top(); sts.pop();
                    sts.push(top + expand);
                }
                idx++;
            }
        }

        return res;
    }
};

