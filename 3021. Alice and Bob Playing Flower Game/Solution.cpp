class Solution {
public:
    long long flowerGame(int n, int m) 
    {
        return (1LL * n * m) - (1LL * (n/2) * (m/2)) - (1LL * (n - n/2) * (m - m/2));     
    }
};