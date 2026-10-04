class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) 
        {
            cnt += (s[i] == ')') ? -1 : 1;
            if (cnt < 0) 
                return false;
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) 
        {
            cnt += (s[i] == '(') ? -1 : 1;
            if (cnt < 0) 
                return false;
        }
        return true;
    }
};