class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        int state = -1, gs = groups.size();
        vector<string> res;
        for(int i=0; i<gs; i++)
        {
            if(state != groups[i])
            {
                state = groups[i];
                res.push_back(words[i]);
            }
        }
        return res;
    }
};