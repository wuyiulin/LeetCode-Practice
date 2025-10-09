class Solution {
using LL = long long;
public:
    long long minTime(vector<int>& skill, vector<int>& mana) 
    {
        LL res = 0;
        int m = skill.size(), n = mana.size();
        vector<LL> table(m, 0LL);
        vector<LL> prefixS(m, 0LL);
        for(int i=0; i<m; i++)
            table[i] = i ? table[i - 1] + skill[i] * mana[0] : skill[0] * mana[0];
        for(int i=0; i<m; i++)
            prefixS[i] = i ? prefixS[i - 1] + skill[i] : skill[i];
        
        for(int j=1; j<n; j++)
        {
            LL startJ = 0;
            for(int i=0; i<m; i++)
            {
                LL preS = i ? prefixS[i - 1] : 0LL;
                LL condi = table[i] - preS * 1LL * mana[j];
                if(condi > startJ)
                    startJ = condi;
            }

            for(int i=0; i<m; i++)
                table[i] = startJ + prefixS[i] * mana[j];
        }

        return table[m-1];
    }
};

