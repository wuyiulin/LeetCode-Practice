class Solution {
public:
    string robotWithString(string s) 
    {
        int table[26], n = s.size(), idx = 0;
        string res = "";
        stack<char> st;
        memset(table, 0 , sizeof(table));
        for(int i=0; i<n; i++)
            table[s[i] - 'a']++;
        for(const auto& c : s)
        {
            table[c - 'a']--;
            st.push(c);
            while('a' + idx < 'z' && !table[idx])
                idx++;
            while(!st.empty() && st.top() <= ('a' + idx))
            {
                res += st.top();
                st.pop();
            }
        }

        return res;
    }
};