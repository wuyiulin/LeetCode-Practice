class Solution {
private:
    int digi(int num)
    {
        int res = 1;
        while(num)
        {
            res *= (num % 10);
            num /= 10;
        }

        return res;
    }
public:
    int smallestNumber(int n, int t) {
        int res = -1;
        for(int curr=n; curr<n+10; curr++)
        {
            if(!(digi(curr)%t))
            {
                res = curr;
                break;
            }
        }
        return res;
    }
};