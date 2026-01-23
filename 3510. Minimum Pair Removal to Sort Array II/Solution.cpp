using LL = long long;
class Solution {
    struct State 
    {
        long long sum;
        int l, r;
        bool operator >(const State& other) const 
        {
            if (sum != other.sum) 
                return sum > other.sum;
            return l > other.l;
        }
    };
public:
    int minimumPairRemoval(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        vector<LL> val(n);
        vector<int> L(n), R(n);
        vector<bool> deleted(n, false);
        priority_queue<State, vector<State>, greater<State>> pq;

        for(int i=0; i<n; i++)
        {
            val[i] = nums[i];
            L[i] = i - 1;
            R[i] = (i == n - 1) ? -1 : i + 1;
        }

        int vios = 0;
        for(int i=0; i<n-1; i++)
        {
            pq.push({val[i] + val[i + 1], i, i + 1});
            if(val[i] > val[i + 1])
                vios++;
        }

        int res = 0;
        while(vios && !pq.empty())
        {
            State top = pq.top(); pq.pop();
            int l = top.l, r = top.r;

            if(deleted[l] || deleted[r] || R[l] != r || (val[l] + val[r] != top.sum))
                continue;

            res++;

            if(L[l] != -1 && val[L[l]] > val[l])
                vios--;
            if(val[l] > val[r])
                vios--;
            if(R[r] != -1 && val[r] > val[R[r]])
                vios--;

            val[l] = val[l] + val[r];
            deleted[r] = true;

            int next = R[r];
            R[l] = next;
            if(next != -1)
                L[next] = l;

            if(L[l] != -1)
            {
                if(val[L[l]] > val[l])
                    vios++;
                pq.push({val[L[l]] + val[l], L[l], l});
            }
            if(R[l] != -1)
            {
                if(val[l] > val[R[l]])
                    vios++;
                pq.push({val[l] + val[R[l]], l, R[l]});
            }
        }

        return res;
    }
};