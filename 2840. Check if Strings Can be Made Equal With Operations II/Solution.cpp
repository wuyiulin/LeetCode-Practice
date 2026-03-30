class Solution {
public:
    bool checkStrings(string s1, string s2) 
    {
        int n = s2.size();
        unordered_map<int, int> odd, even;
        for(int i=0; i<s1.size(); i++)
        {
            if(i%2)
                odd[s2[i]]++;
            else
                even[s2[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            int tar = s1[i];
            if(i%2 && odd.count(tar))
            {
                odd[tar]--;
                if(!odd[tar])
                    odd.erase(tar);
            }
                
            else if(!(i%2) && even.count(tar))
            {
                even[tar]--;
                if(!even[tar])
                    even.erase(tar);
            }
            else
                return false;   
        }

        return true;
    }
};