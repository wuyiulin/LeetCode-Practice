class Solution {
public:
    string makeLargestSpecial(string s) 
    {
        if(s.empty())
            return s;
        vector<string> table = {};
        int state = 0, startIdx = 0, n = s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i] == '1')
                state += 1;
            else
                state -= 1;
            
            if(!state)
            {
                string inner = s.substr(startIdx + 1, i - startIdx - 1);
                string curr = "1" + makeLargestSpecial(inner) + "0";
                table.push_back(curr);
                startIdx = i + 1;
            }
        }
        sort(table.begin(), table.end(), greater<string>());
        s = "";
        for(const auto& t : table)
            s += t;

        return s;
    }
};