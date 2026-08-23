class Solution {
private:
    double getNum(char ch)
    {
        return ch == '?' ? 4.5 : ch - '0'; 
    }
public:
    bool sumGame(string num) {
        int n = num.size();
        double curr = 0;
        for(int i=0; i<n/2; i++)
            curr += getNum(num[i]);
        for(int i=n/2; i<n; i++)
            curr -= getNum(num[i]);
        
        return curr != 0.0;
    }
};