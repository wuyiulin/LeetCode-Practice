class Solution {
using LL = long long;
private:
    string to_k_base(LL curr, int k) 
    {
        if (curr == 0) return "0";
        string res = "";
        while(curr > 0) 
        {
            int digit = curr % k;
            res += ('0' + digit);
            curr /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isPalindrome(const string& s) 
    {
        int n = s.size();
        for(int i = 0; i < n/2; i++) 
        {
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    
    vector<LL> generatePalindromes(int length) 
    {
        vector<LL> palindromes;
        
        if (length == 1) 
        {
            for (int i = 1; i <= 9; i++) 
                palindromes.push_back(i);
                
            return palindromes;
        }
        
        int halfLen = (length + 1) / 2;
        LL start = 1;
        for (int i = 1; i < halfLen; i++) 
            start *= 10;

        LL end = start * 10;
        
        for (LL i = start; i < end; i++) 
        {
            string half = to_string(i);
            string palindrome = half;
            
            if (length % 2 == 0) 
            {
                string reversed = half;
                reverse(reversed.begin(), reversed.end());
                palindrome += reversed;
            } 
            else 
            {
                string reversed = half.substr(0, half.length() - 1);
                reverse(reversed.begin(), reversed.end());
                palindrome += reversed;
            }
            
            palindromes.push_back(stoll(palindrome));
        }
        
        return palindromes;
    }

public:
    long long kMirror(int k, int n) {
        LL res = 0;
        int count = 0;
        
        for (int length = 1; count < n; length++) 
        {
            vector<LL> palindromes = generatePalindromes(length);
            
            for (LL palindrome : palindromes) 
            {
                if (count >= n) 
                    break;
                
                string kStr = to_k_base(palindrome, k);
                if (isPalindrome(kStr)) 
                {
                    res += palindrome;
                    count++;
                }
            }
        }
        
        return res;
    }
};