class Solution 
{
public:
    int maxDiff(int num) 
    {
        string s = to_string(num);
        int n = s.size();
        char maxInt = 'a', minInt = 'a';
        bool firstOne = false;

        for(int i=0; i<n; i++)
        {
            if(s[i] != '9')
            {
                maxInt = s[i];
                break;
            }
        }

        if(s[0] != '1')
        {
            minInt = s[0];
            firstOne = true;
        }
        else
        {
            for(int i=1; i<n; i++)
            {
                if(s[i] != '0' && s[i] != '1')
                {
                    minInt = s[i];
                    break;
                }
            }
        }

        string maxS = "", minS = "";
        for(int i=0; i<n; i++)
        {
            char maxTmp = s[i], minTmp = s[i];

            if(s[i] == maxInt)
                maxTmp = '9';

            if(s[i] == minInt)
            {
                if(firstOne)
                    minTmp = '1';
                else
                    minTmp = '0';
            }

            maxS += maxTmp;
            minS += minTmp;
        }

        return stoi(maxS) - stoi(minS);
    }
};
