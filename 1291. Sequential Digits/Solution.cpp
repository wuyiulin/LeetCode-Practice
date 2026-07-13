class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> res;
        string s = "123456789";
        int ls = 0, hs = 0;
        while(1*pow(10, ls) <= low)
            ls++;
        while(1*pow(10, hs) <= high)
            hs++;

        while(ls <= hs)
        {
            for(int l=0; l+ls<=9; l++)
            {
                int curr = stoi(s.substr(l, ls));
                if(low <= curr && curr <= high)
                    res.push_back(curr);
            }
            ls++;
        }

        return res;
    }
};