class Solution {
private:
    void recordVowel(int* table, const char& c)
    {
        switch(c)
        {
            case('A'):
                table[0]++;
                break;
            case('E'):
                table[1]++;
                break;
            case('I'):
                table[2]++;
                break;
            case('O'):
                table[3]++;
                break;
            case('U'):
                table[4]++;
                break;
            case('a'):
                table[5]++;
                break;
            case('e'):
                table[6]++;
                break;
            case('i'):
                table[7]++;
                break;
            case('o'):
                table[8]++;
                break;
            case('u'):
                table[9]++;
                break;
        }
    }
public:
    string sortVowels(string s) 
    {
        int table[10], idx = 0;
        string v = "AEIOUaeiou";
        static unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        memset(table, 0, sizeof(table));
        for(const auto& c : s)
            recordVowel(table, c);
        for(int i=0; i<s.size(); i++)
        {
            if(vowels.count(s[i]))
            {
                while(!table[idx] && idx < 10)
                    idx++;
                if(idx == 10)
                    break;
                s[i] = v[idx];
                table[idx]--;
            }
        }

        return s;
    }
};