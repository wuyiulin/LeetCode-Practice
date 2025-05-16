class Solution
{
private:
    bool check(string& a, string& b)
    {
        int na = a.size(), nb = b.size(), cnt = 0;
        cnt += abs(na - nb);
        na = max(na, nb);
        for(int i = 0; i < na; i++)
        {
            if(a[i] != b[i])
            {
                cnt++;
                if(cnt > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        int n = words.size();
        vector<vector<string>> dp(n);

        for(int i = 0; i < n; i++)
        {
            dp[i].push_back(words[i]);

            for(int j = 0; j < i; j++)
            {
                if(groups[i] != groups[j] && check(words[j], words[i]))
                {
                    if(dp[j].size() + 1 > dp[i].size())
                    {
                        dp[i] = dp[j];
                        dp[i].push_back(words[i]);
                    }
                }
            }
        }

        vector<string> res;
        for(auto& seq : dp)
            if(seq.size() > res.size())
                res = seq;

        return res;
    }
};
