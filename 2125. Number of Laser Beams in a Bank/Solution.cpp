class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int n = bank.size(), pre = 0, res = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            int curr = 0;
            for(int j=0; j<bank[i].size(); j++)
                curr += (bank[i][j] - '0');
            if(i != n-1)
                res += (pre * curr);
            if(curr)
                pre = curr;
        }

        return res;
    }
};