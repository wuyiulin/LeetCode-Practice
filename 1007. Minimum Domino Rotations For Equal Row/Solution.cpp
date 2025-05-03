class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        vector<int> tar = {tops[0], bottoms[0]};
        int res = INT_MAX, n = tops.size();
        for(const auto& t : tar)
        {
            bool vaild = true;
            int cnt1 = 0, cnt2 = 0;
            for(int i=0; i<n; i++)
            {

                if(tops[i] != t && bottoms[i] != t)
                {
                    vaild = false;
                    break;
                }
                else if(tops[i] != t && bottoms[i] == t) cnt1++;
                else if(tops[i] == t && bottoms[i] != t) cnt2++;
            }
            if(!vaild) continue;
            cnt1 = min(cnt1, cnt2);
            res = min(res, cnt1);
        }

        return res == INT_MAX ? -1 : res;
    }
};