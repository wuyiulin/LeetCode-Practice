class Solution {
public:
    string makeFancyString(string s) 
    {
        char pre = 'A';
        int cnt = 0, n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] != pre)
            {
                cnt = 1;
                pre = s[i];
            }
            else
                cnt++;
            if(cnt >= 3)
                s[i] = 'A';
        }

        s.erase(remove(s.begin(), s.end(), 'A'), s.end());

        return s;
    }
};