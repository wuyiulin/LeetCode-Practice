class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        int broken[26], res = 0, n = text.size();
        memset(broken, 0, sizeof(broken));
        for(const auto& c : brokenLetters)
            broken[c - 'a'] = 1;
        
        bool f = true;
        for(int i=0; i<n; i++)
        {
            f = true;
            if(text[i] != ' ' && broken[text[i] - 'a'])
            {
                while(text[i] != ' ' && i < n)
                    i++;
                f = false;
            }
            if(text[i] == ' ' && f)
                res++;
        }

        return f ? res + 1 : res;
    }
};