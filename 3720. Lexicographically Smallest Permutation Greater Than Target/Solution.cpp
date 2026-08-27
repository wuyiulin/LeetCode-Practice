class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size(), idx = 0, freq[26];
        memset(freq, 0, sizeof(freq));
        string prev = "";
        for(const auto& ch : s)
            freq[ch - 'a']++;
        s = "";
        for(int i=0; i<n; i++)
        {
            int ti = target[i] - 'a';
            if(freq[ti] > 0)
            {
                prev += ('a' + ti);
                freq[ti]--;
                idx++;
            }
            else
                break;
        }

        while(1)
        {
            if(idx < n)
            {
                int pick = -1;
                for(int i=target[idx] - 'a' + 1; i<26; i++)
                {
                    if(freq[i] > 0)
                    {
                        pick = i;
                        break;
                    }
                }
                if(pick != -1)
                {
                    s += target.substr(0, idx);
                    s += ('a' + pick);
                    freq[pick]--;
                    for (int c = 0; c < 26; c++)
                        s.append(freq[c], ('a' + c));
                    
                    return s;
                }
            }
            if(!idx)
                break;
            idx--;
            freq[prev[idx] - 'a']++;
        }

        return "";
    }
};