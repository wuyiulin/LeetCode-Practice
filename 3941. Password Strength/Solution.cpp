class Solution {
public:
    int passwordStrength(string password) 
    {
        unordered_set<char> s;
        int res = 0;
        for(const char ch : password)
        {
            int pt = 0;
            if('a'<=ch && ch <= 'z')
                pt = 1;
            else if('A'<=ch && ch<='Z')
                pt = 2;
            else if('0'<=ch && ch<='9')
                pt = 3;
            else
                pt = 5;
            
            if(!s.count(ch))
            {
                s.insert(ch);
                res += pt;
            }
        }

        return res;
    }
};