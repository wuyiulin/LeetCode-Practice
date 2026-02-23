class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int n = s.size();
        unordered_set<int> st;
        for(int i=0; i<(1<<k); i++)
            st.insert(i);
        
        for(int i=0; i<n-k+1; i++)
        {
            int curr = 0;
            for(int j=i+k-1; j>=i; j--)
            {
                if(s[j] == '1')
                    curr += (1 << ((i+k-1) - j));
            }
            if(st.count(curr))
                st.erase(curr);
        }


        return st.empty();
    }
};