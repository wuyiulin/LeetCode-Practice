class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> res = {};
        unordered_set<string> visited;
        stack<string> st;
        st.push(expression);
        
        while(!st.empty())
        {
            string str = st.top(); st.pop();
            if(str.find('{') == string::npos)
            {
                if(!visited.count(str))
                {
                    visited.insert(str);
                    res.push_back(str);
                }
                continue;
            }

            int i = 0, l = 0, r = 0;
            while(str[i] != '}')
            {
                if(str[i++] == '{')
                    l = (i - 1);
            }
            r = i;
            string prev = str.substr(0, l);
            string post = str.substr(r + 1);
            string curr = str.substr(l + 1, r - l - 1);
            istringstream iss(curr);
            string s;
            while(getline(iss, s, ','))
                st.push(prev + s + post);
        }

        sort(res.begin(), res.end());

        return res;
    }
};