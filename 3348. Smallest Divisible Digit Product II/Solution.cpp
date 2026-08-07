class Solution {
private:
    static inline const unordered_map<int, unordered_map<int, int>> kFactorCnt = {
      {0, {}},       {1, {}},       {2, {{2, 1}}},         {3, {{3, 1}}},
      {4, {{2, 2}}}, {5, {{5, 1}}}, {6, {{2, 1}, {3, 1}}}, {7, {{7, 1}}},
      {8, {{2, 3}}}, {9, {{3, 2}}}};
    pair<unordered_map<int, int>, bool> getPrimeCount(long t)
    {
        unordered_map<int, int> cnt{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for(const int prime : {2, 3, 5, 7})
        {
            while(!(t % prime))
            {
                t /= prime;
                cnt[prime]++;
            }
        }

        return {cnt, t == 1};
    }
    int sumVal(const unordered_map<int, int>& cnt)
    {
        return accumulate(cnt.begin(), cnt.end(), 0, [](int acc, const pair<int, int>& p) {return acc + p.second;});
    }
    string consturct(const unordered_map<int, int>& factors)
    {
        string res = "";
        for(int digit=2; digit<10; digit++)
            res += string(factors.at(digit), '0' + digit);

        return res;
    }
    unordered_map<int, int> getPrimeCount(const string& num)
    {
        unordered_map<int, int> cnt{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for(const char d : num)
            for(const auto& [prime, freq] : kFactorCnt.at(d - '0'))
                cnt[prime] += freq;
        
        return cnt;
    }
    unordered_map<int, int> substract(unordered_map<int, int> a, const unordered_map<int, int>& b)
    {
        for(const auto& [key, value] : b)
            a[key] = max(0, a[key] - value);
        
        return a;
    }
    unordered_map<int, int> getFactorCount(const unordered_map<int, int>& count) {
        unordered_map<int, int> res;
        const int count8 = count.at(2) / 3;
        const int remaining2 = count.at(2) % 3;
        const int count9 = count.at(3) / 2;
        int count3 = count.at(3) % 2;
        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;
        int count6 = 0;
        if (count2 == 1 && count3 == 1) {
        count2 = 0;
        count3 = 0;
        count6 = 1;
        }
        if (count3 == 1 && count4 == 1) {
        count2 = 1;
        count6 = 1;
        count3 = 0;
        count4 = 0;
        }
        
        return unordered_map<int, int>{
            {2, count2}, {3, count3},      {4, count4}, {5, count.at(5)},
            {6, count6}, {7, count.at(7)}, {8, count8}, {9, count9}};
    }
    bool isSubset(const unordered_map<int, int>& a, const unordered_map<int, int>& b)
    {
        for(const auto& [key, value] : a)
            if(b.at(key) < value)
                return false;
        
        return true;
    }
public:
    string smallestNumber(string num, long long t) {
        int n = num.size();
        const auto[pCnt, isDiv] = getPrimeCount(t);
        if(!isDiv)
            return "-1";
        
        const unordered_map<int, int> factorCnt = getFactorCount(pCnt);
        if(sumVal(factorCnt) > n)
            return consturct(factorCnt);
        
        unordered_map<int, int> pCntPrefix = getPrimeCount(num);
        int firstZeroIdx = num.find('0');
        if(firstZeroIdx == string::npos)
        {
            firstZeroIdx = n;
            if(isSubset(pCnt, pCntPrefix))
                return num;
        }
        for(int i=n - 1; i>=0; i--)
        {
            const int d = num[i] - '0';
            pCntPrefix = substract(pCntPrefix, kFactorCnt.at(d));
            const int space = n - 1 - i;
            if(i > firstZeroIdx)
                continue;
            for(int bDigit=d+1; bDigit<10; bDigit++)
            {
                const unordered_map<int, int> factorAfterReplace = getFactorCount(substract(substract(pCnt, pCntPrefix), kFactorCnt.at(bDigit)));
                if(sumVal(factorAfterReplace) <= space)
                {
                    const int fillOnes = space - sumVal(factorAfterReplace);
                    
                    return num.substr(0, i) + to_string(bDigit) + string(fillOnes, '1') + consturct(factorAfterReplace); 
                }
            }
        }

        const unordered_map<int, int> factorAfterEx = getFactorCount(pCnt);

        return string(n + 1 - sumVal(factorAfterEx), '1') + consturct(factorAfterEx);
    }
};