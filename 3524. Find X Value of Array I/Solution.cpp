class Solution {
    using LL = long long;
    public:
        vector<long long> resultArray(vector<int>& nums, int k) 
        {
            int n = nums.size();
            vector<LL> res(k, 0);
            vector<vector<int>> rec(2, vector<int>(k, 0));
            for(int i=0; i<n; i++)
            {
                rec[1][nums[i] % k ] = 1;
                for(int j=0; j<k; j++)
                {
                    int pre = rec[0][j];
                    LL newRed = (1LL * j * nums[i]) % k;
                    rec[1][newRed] += pre; 
                }
    
                for(int t=0; t<k; t++) res[t] += rec[1][t];
                for(int j=0; j<k; j++)
                {
                    rec[0][j] = rec[1][j];
                    rec[1][j] = 0;
                }
            }
    
            return res;
            
            
        }
    };
    
    