class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int v1s = version1.size(), v2s = version2.size();
        vector<int> t1 = {}, t2 = {};
        for(int r=0, l=0; r<v1s; r++)
        {
            if(version1[r] == '.' || r == v1s-1)
            {
                if(r == v1s-1)
                    r++;
                t1.push_back( stoi(version1.substr(l, r-l)) ); 
                l = r + 1;
            }
        }
        for(int r=0, l=0; r<v2s; r++)
        {
            if(version2[r] == '.' || r == v2s-1)
            {
                if(r == v2s-1)
                    r++;
                t2.push_back( stoi(version2.substr(l, r-l)) );
                l = r + 1;
            }
        }
        int t1s = t1.size(), t2s = t2.size();
        for(int i=0; i<max(t1s, t2s); i++)
        {
            int v1 = 0, v2 = 0;
            if(i<t1s)
                v1 = t1[i];
            if(i<t2s)
                v2 = t2[i];

            if(v1 != v2)
                return v1 > v2 ? 1 : -1;
        }

        return 0;
    }
};