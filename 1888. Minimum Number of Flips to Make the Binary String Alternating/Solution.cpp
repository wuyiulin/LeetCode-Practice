class Solution {
public:
    int minFlips(string s) 
    {
        int n = s.size(), standard = 0, curr = 0;
        string ts = "10";
        for(int i=0; i<n; i++)
        {
            if(s[i] != ts[i % 2])
                curr++;
        }
        standard = min(curr, n - curr);
        
        for(int i=0; i<n; i++)
        {
            if(s[i] != ts[i%2])
                curr--;
            if(s[i] != ts[(i+n) %2])
                curr++;
            standard = min({standard, curr, n - curr});
        }

        return standard;
    }
};