class Solution {
using LL = long long;
public:
    static const LL CAP = 2e6;

    LL combCapped(LL n, LL r) 
    {
        if (r > n - r) r = n - r;
        LL res = 1;
        for (LL i = 0; i < r; i++) {
            res = res * (n - i) / (i + 1);
            if (res >= CAP) 
                return CAP;
        }
        return res;
    }

    LL permCountCapped(vector<int>& half) 
    {
        LL res = 1;
        LL placed = 0;
        for (int c = 0; c < 26; c++) 
        {
            if (half[c] == 0) 
                continue;
            placed += half[c];
            LL comb = combCapped(placed, half[c]);
            res *= comb;
            if (res >= CAP) 
                return CAP;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char ch : s) count[ch - 'a']++;

        char mid = 0;
        bool hasMid = false;
        vector<int> half(26, 0);
        for (int c = 0; c < 26; c++) 
        {
            if (count[c] % 2 == 1) 
            {
                mid = 'a' + c;
                hasMid = true;
            }
            half[c] = count[c] / 2;
        }

        LL kk = k;

        LL total = permCountCapped(half);
        if (total < kk) 
            return "";

        int halfLen = n / 2;
        string halfStr = "";

        for (int i = 0; i < halfLen; i++) 
        {
            for (int c = 0; c < 26; c++) 
            {
                if (half[c] == 0) 
                    continue;
                half[c]--;
                long long cnt = permCountCapped(half);
                if (cnt >= kk) 
                {
                    halfStr += ('a' + c);
                    break;
                } 
                else 
                {
                    kk -= cnt;
                    half[c]++;
                }
            }
        }

        string res = halfStr;
        if (hasMid) 
            res += mid;
        string rev = halfStr;
        reverse(rev.begin(), rev.end());
        res += rev;

        return res;
    }
};