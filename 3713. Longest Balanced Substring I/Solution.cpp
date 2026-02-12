class Solution {
public:
    int longestBalanced(string s) 
    {
        int res = 0, n = s.size();
        for(int i=0; i<n; i++)
        {
            int table[26];
            memset(table, 0, sizeof(table));
            for(int j=i; j<n; j++)
            {
                bool f = true;
                table[s[j] - 'a']++;
                int curr = -1;
                for(int k=0; k<26; k++)
                {
                    if(curr == -1 && table[k] > 0)
                        curr = table[k];
                    if(curr != -1 && table[k] > 0 && curr != table[k])
                    {
                        f = false;
                        break;
                    }
                }

                if(f)
                    res = max(res, j - i + 1);
            }

        }

        return res;
    }
};