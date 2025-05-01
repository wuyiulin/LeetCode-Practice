class Solution {
private:
    bool helper(vector<int>& tasks, multiset<int> ms, int pills, int s, int num)
    {
        if(num > ms.size()) return false;
        for(int i=num-1; i>=0; i--)
        {
            if(*ms.rbegin() >= tasks[i])
            {
                ms.erase(prev(ms.end()));
            }
            else
            {
                if(!pills) return false;
                auto it = ms.lower_bound(tasks[i] - s);
                if(it == ms.end()) return false;
                else ms.erase(it);
                pills--;
            }
        }

        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        multiset<int> ms(workers.begin(), workers.end());
        int l = 0, r = tasks.size(), res = 0;
        while(l<r)
        {
            int mid = l + (r - l + 1) / 2;
            if(helper(tasks, ms, pills, strength, mid))
            {
                l = mid;
                res = mid;
            }
            else r = mid - 1;
        }

        return res;
    }
};