class Solution {
    unordered_map<string, string> memo;
private:
    bool dfs(vector<string>& pyra, unordered_map<string, vector<char>>& table, int l, int i)
    {
        bool f = false;
        int n = pyra[l].size();
        if(!l)
            return true;
        if(!i && memo.count(pyra[l]))
        {
            pyra[l - 1] = memo[pyra[l]];
            f = dfs(pyra, table, l - 1, 0);
            if(!f)
            {
                pyra[l - 1] = "";
                return false;
            }
            else
                return true;
        }
        if(i == l)
        {
            f = dfs(pyra, table, l - 1, 0);
            memo[pyra[l]] = pyra[l - 1];
        }
        else
        {
            string tar = pyra[l].substr(i, 2);
            if(table.count(tar))
            {
                for(const auto& c : table[tar])
                {
                    pyra[l - 1].push_back(c);
                    f = dfs(pyra,table, l, i + 1);
                    if(!f)
                    {
                        pyra[l - 1].pop_back();
                    }
                    else
                    {
                        f = true;
                        return true;
                    }
                }
            }
        }
    
        return f;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) 
    {
        int l = bottom.size() - 1;
        vector<string> pyra(l + 1, "");
        unordered_map<string, vector<char>> table;
        for(const auto& all : allowed)
            table[all.substr(0, 2)].push_back(all.back());
        pyra[l] = bottom;
        return dfs(pyra, table, l, 0);
    }
};