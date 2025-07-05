class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char, int> ref, curr;
        for(const auto& c : t)
            ref[c]++;
        int rs = ref.size(), vs = 0;
        int l = 0, r = 0, res = INT_MAX, start = -1;
        while(r < s.size())
        {
            char tar = s[r];
            curr[tar]++;
            if(ref.count(tar) && curr[tar] == ref[tar])
                vs++;
            while(vs == rs && l <= r)
            {
                int dist = r - l + 1;
                if(dist < res)
                {
                    res = dist;
                    start = l;
                }
                
                curr[s[l]]--;
                if(ref.count(s[l]) && curr[s[l]] < ref[s[l]])
                    vs--;
                l++;
            }
            r++;
        }    

        return start == -1 ? "" : s.substr(start, res);
    }
};