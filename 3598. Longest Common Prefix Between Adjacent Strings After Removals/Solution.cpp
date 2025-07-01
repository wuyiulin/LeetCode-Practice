class Solution {
private:
    int getLCP(string& s1, string& s2)
    {
        int n = min(s1.size(), s2.size()), i = 0;
        while(i < n)
        {
            if(s1[i] != s2[i])
                break;
            i++;
        }

        return i;
    }

public:
    vector<int> longestCommonPrefix(vector<string>& words) 
    {
        int n = words.size();
        vector<int> lcp(n - 1, 0), res(n, 0);
        vector<int> prefMax(n - 1, 0), surfMax(n - 1, 0);
        if(n <= 1) 
            return res;
        for(int i=0; i<n-1; i++)
            lcp[i] = getLCP(words[i], words[i + 1]);
        prefMax[0] = lcp[0];
        for(int i=1; i<n-1; i++)
            prefMax[i] = max(prefMax[i - 1], lcp[i]);
        surfMax[n - 2] = lcp[n - 2];    
        for(int i=n-3; i>=0; i--)
            surfMax[i] = max(surfMax[i + 1], lcp[i]);

        for(int i=0; i<n; i++)
        {
            int curr = 0;
            if(i >= 2)
                curr = max(curr, prefMax[i - 2]);
            if(i + 1 <= n - 2)
                curr = max(curr, surfMax[i + 1]);
            if(i > 0 && i < n - 1)
                curr = max(curr, getLCP(words[i - 1], words[i + 1]));
            res[i] = curr;
        }
    
        return res;
    }
};