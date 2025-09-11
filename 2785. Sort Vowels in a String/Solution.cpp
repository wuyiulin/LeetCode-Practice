class Solution {
public:
    string sortVowels(string s) 
    {
        int idx = 0;
        string v = "AEIOUaeiou";
        unordered_set<char> st = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, pair<int, int>> m; // {char, {idx, nums}}
        for(int i=0; i<v.size(); i++)
            m[v[i]] = {i, 0};

        for(const auto& c : s)
        {
            if(st.count(c))
                m[c].second++;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(m.count(s[i]))
            {
                char cdx = v[idx];
                while(!m[cdx].second && idx < 10)
                {
                    idx++;
                    cdx = v[idx];
                }
                if(idx == 10)
                    break;
                s[i] = v[idx];
                m[cdx].second--;
            }
        }

        return s;
    }
};