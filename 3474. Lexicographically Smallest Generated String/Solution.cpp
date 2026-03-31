class Solution {
public:
    string generateString(string str1, string str2) 
    {
        int n = str1.size(), m = str2.size();
        string res(n + m - 1, '#');
        for(int i=0; i<n; i++)
        {
            if(str1[i] == 'T')
            {
                for(int j=i; j<i+m; j++)
                {
                    if(res[j] == '#')
                        res[j] = str2[j - i];
                    else if(res[j] != str2[j - i])
                        return "";
                }
            }
        }
        for(int i=0; i<m+n; i++)
        {
            if (res[i] != '#') 
                continue;
            for (char c = 'a'; c <= 'z'; c++) 
            {
                res[i] = c;
                bool ok = true;
                for (int j = max(0, i - m + 1); j <= min(i, n - 1); j++)
                {
                    if (str1[j] == 'F') 
                    {
                        bool isFull = false;
                        for (int k = 0; k < m; k++) 
                        {
                            if (res[j + k] == '#') 
                            {
                                isFull = true;
                                break;
                            }
                        }
                        if (!isFull && res.substr(j, m) == str2) 
                        {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) 
                    break;
                if (c == 'z')
                    return "";
            }
        }

        for (int i = 0; i < n; i++) 
        {
            string sub = res.substr(i, m);
            if (str1[i] == 'F' && sub == str2) 
                return "";
        }

        return res;
    }
};