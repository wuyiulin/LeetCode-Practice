class Solution {
public:
    int numTilings(int n) 
    {
        int MOD = 1e9 + 7;
        vector<int> domi(4, 0);
        domi[0] = 1;
        domi[1] = 2;
        domi[2] = 5;
        for(int i=4; i<=n; i++)
        {
            domi[3] = (2 * domi[2] % MOD + domi[0] % MOD) % MOD;
            domi[0] = domi[1];
            domi[1] = domi[2];
            domi[2] = domi[3];
            
        }

        return n>=4 ? domi[3] : domi[n-1];
    }
};