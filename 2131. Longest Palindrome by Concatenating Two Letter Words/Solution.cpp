class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> table;
        int res = 0;
        bool mid = false;
        for(const auto& word : words) 
            table[word]++;
        for(auto& [key, cnt] : table)
        {
            if(!cnt) continue;
            string rKey = key;
            reverse(rKey.begin(), rKey.end());
            if(key == rKey)
            {
                int pairs = table[key] / 2;
                res += (pairs * 4);
                if(table[key] % 2)
                    mid = true;
                table[key] = 0;
            }
            else if(table[key] && table.count(rKey) && table[rKey])
            {
                int rCnt = table[rKey];
                cnt = min(cnt, rCnt);
                res += (cnt * 4);
                table[key] = 0;
                table[rKey] = 0;
            }
        }

        return mid ? res + 2 : res;
    }
};