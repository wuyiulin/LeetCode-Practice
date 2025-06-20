class Solution {
private:
    int count(const string& s, int k, const vector<char>& dir)
    {
        int cnt = 0, flip = 0, res = 0;
        for(const auto& c : s)
        {
            if(c != dir[0] && c != dir[1])
            {
                cnt--;
                flip++;
            }
            else
                cnt++;
            res = max(res, cnt + 2 * min(k, flip));
        }

        return res;
    }
public:
    int maxDistance(string s, int k) 
    {
        vector<vector<char>> dirs = {{'N', 'W'}, {'N', 'E'}, {'S', 'W'}, {'S', 'E'}};
        int res = 0;
        for(const auto& dir : dirs)
            res = max(res, count(s, k, dir));

        return res;
    }
};