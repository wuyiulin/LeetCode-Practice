class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int n = strs.size(), m = strs[0].size();
        int res = 0;
        vector<string> ref(n, "");
        for(int i=0; i<m; i++)
        {
            vector<string> curr = ref;
            int j = 0;
            for(; j<n; j++)
            {
                curr[j] += strs[j][i];
                if(j && curr[j] < curr[j - 1])
                {
                    res++;
                    break;
                }
            }
            if(j==n)
                ref = curr; 
        }

        return res;
    }
};