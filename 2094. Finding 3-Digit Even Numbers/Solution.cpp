class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        int table[10];
        memset(table, 0, sizeof(table));
        for(const auto& d : digits) table[d]++;
        string maxS = "";
        while(maxS.size() < 3)
        {
            for(int i=9; i>=0; i--)
            {
                if(table[i] >= 3 - maxS.size()) maxS += string(3 - maxS.size(), i + '0');
                else maxS += string(table[i], i + '0');
            }
        }
        int maxNum = stoi(maxS);
        vector<int> res = {};
        for(int i=100; i<=maxNum; i=i+2)
        {
            string s = to_string(i);
            int cnt[10];
            bool f = true;
            memset(cnt, 0, sizeof(cnt));
            for(const auto& c : s) cnt[c - '0']++;
            for(int idx=0; idx<10; idx++)
            {
                if(cnt[idx] > table[idx])
                {
                    f = false;
                    break;
                } 
            }
            if(f) res.push_back(i);
        }

        return res;
    }
};