class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        int n = s.size(), m = goal.size();
        if(n != m)
            return false;
        for(int i=0; i<n; i++)
        {
            int j = 0;
            bool f = true;
            while(j < n && f)
            {
                int sIdx = (i + j) % n;
                if(s[sIdx] != goal[j])
                    f = false;
                j++;
            }
            if(f)
                return true;
        }

        return false;
    }
};