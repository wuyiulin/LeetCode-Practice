class Solution {
private:
    bool isful(int n)
    {
        int table[10];
        memset(table, 0, sizeof(table));
        while(n)
        {
            table[n%10]++;
            n /= 10;
        }
        for(int i=0; i<10; i++)
        {
            if(table[i] && table[i] != i)
                return false;
        }

        return true;
    }
public:
    int nextBeautifulNumber(int n) 
    {
        while(++n <= INT_MAX)
        {
            if(isful(n))
                return n;
        }

        return -1;
    }
};