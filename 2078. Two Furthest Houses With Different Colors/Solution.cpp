class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), res = 0;
        
        for (int i = n - 1; i > 0; i--) 
        {
            if (colors[i] != colors[0]) 
            {
                res = max(res, i);
                break;
            }
        }
        
        for (int i = 0; i < n - 1; i++) 
        {
            if (colors[i] != colors[n - 1]) 
            {
                res = max(res, (n - 1) - i);
                break;
            }
        }
        
        return res;
    }
};