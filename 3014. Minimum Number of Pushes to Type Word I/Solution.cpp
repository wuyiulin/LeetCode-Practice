class Solution {
public:
    int minimumPushes(string word) {
        int table[26], l = 1, capa = 8, res = 0;
        memset(table, 0, sizeof(table));
        for(const auto& ch : word)
            table[ch - 'a']++;
        sort(table, table + 26, greater<int>());
        for(int i=0; i<26 && table[i]>0; i++)
        {
            if(capa == 0)
            {
                l++;
                capa = 8;
            }
            capa--;
            res += (l * table[i]);
        }

        return res;
    }
};