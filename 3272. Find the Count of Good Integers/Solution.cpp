class Solution {
public:
    long long countGoodIntegers(int n, int k) 
    {
        long long res = 0;
        int base = pow(10, (n-1)/2);
        long long fac[11];
        unordered_set<string> vis;
        fill(fac, fac + 11, 1LL);
        for(int i=1; i<11; i++) fac[i] = fac[i-1] * i;
        for(int curr=base; curr<base*10; curr++)
        {
            string currS = to_string(curr);
            currS += string(currS.rbegin() + (n%2), currS.rend());
            if(stoll(currS) % k) continue;
            sort(currS.begin(), currS.end());
            if(vis.count(currS)) continue;
            vis.insert(currS);
            int cs = currS.size();
            int rec[10];
            memset(rec, 0, sizeof(rec));
            for(const auto& c : currS) rec[c - '0']++;
            long long cnt = 0;
            cnt = (n - rec[0]) * fac[cs - 1];
            for(const auto& r : rec) cnt /= fac[r];
            res += cnt;
        }

        return res;
    }
};

