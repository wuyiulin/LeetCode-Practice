class Solution {
using LL = long long;
LL MOD = 1e9 + 7;
private:
    LL powMOD(LL x, LL p)
    {
        LL res = 1;
        while(p)
        {
            if(p&1) res = res * x % MOD;
            x = x * x % MOD;
            p >>= 1;
        }

        return res;
    }
    vector<int> cntPrime(int n)
    {
        vector<int> e(n + 1, 0);
        for(int i=2; i<=n; i++)
        {
            if(!e[i])
            {
                for(int j=i; j<=n; j+=i)
                {
                    e[j]++;
                }
            }
        }

        return e;
    }

public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int MAX = *max_element(nums.begin(), nums.end());
        vector<int> prime = cntPrime(MAX);
        vector<int> scores(n, 0);
        for(int i=0; i<n; i++)
        {
            scores[i] = prime[nums[i]];
        }
        vector<int> preL(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && scores[st.top()] < scores[i])
            {
                st.pop();
            }
            if(!st.empty()) preL[i] = st.top();
            st.push(i);
        }
        vector<int> nextL(n, n);
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && scores[st.top()] <= scores[i])
            {
                st.pop();
            }
            if(!st.empty()) nextL[i] = st.top();
            st.push(i);
        }
        vector<pair<LL, LL>> group(n);
        for(int i=0; i<n; i++)
        {
            LL cnts = 1LL * (i - preL[i]) * (nextL[i] - i);
            group[i] = {nums[i], cnts};
        }
        sort(group.begin(), group.end(), greater());

        LL res = 1;
        for(int i=0; i<n && k > 0; i++)
        {
            const auto& [num, cnt] = group[i];
            if(k >= cnt) res = res * powMOD(num, cnt) % MOD;
            else res = res * powMOD(num, k) % MOD;
            k -= cnt;
        }

        return res;
    }
};