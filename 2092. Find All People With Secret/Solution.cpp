class DSU
{
public:
    vector<int> v;
    DSU(int n)
    {
        v.resize(n);
        iota(v.begin(), v.end(), 0);
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        v[fa] = fb;
    }

    int find(int a)
    {
        if(a == v[a])
            return a;
        return v[a] = find(v[a]);
    }

    void unmerge(int a)
    {
        v[a] = a;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        int ms = meetings.size();
        vector<bool> table(n, false);
        table[0] = true;
        table[firstPerson] = true;
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
        DSU u(n);
        int i = 0;
        while(i<ms)
        {
            int time = meetings[i][2], j = i;
            while(j<ms && meetings[j][2] == time)
            {
                int a = meetings[j][0], b = meetings[j][1];
                int fa = u.find(a), fb = u.find(b);
                if(table[fa])
                    u.merge(b, a);
                else
                    u.merge(a, b);
                j++;
            }
            for(int k=i; k<j; k++)
            {
                int a = meetings[k][0], b = meetings[k][1];
                int fa = u.find(a), fb = u.find(b);
                if(table[fa] || table[fb])
                {
                    table[a] = true;
                    table[b] = true;
                }
                else
                {
                    u.unmerge(a);
                    u.unmerge(b);
                }
            }

            i = j;
        }

        vector<int> res = {};
        for(int i=0; i<n; i++)
            if(table[i])
                res.push_back(i);

        return res;
    }
};