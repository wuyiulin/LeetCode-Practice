class Solution {
public:
    int findKthNumber(int n, int k) 
    {
        int curr = 1;
        k--;
        while(k)
        {
            long long step = 0, first = curr, last = curr + 1;
            while(first<=n)
            {
                step += min((long long)n + 1, last) - first;
                first *=10;
                last *=10;
            }
            if(step<=k)
            {
                curr++;
                k -= step;
            }
            else
            {
                curr *=10;
                k--;
            }
        }
        return curr;
        
    }
};