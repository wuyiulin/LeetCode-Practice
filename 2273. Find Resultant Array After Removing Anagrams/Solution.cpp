class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        unordered_set<string> s;
        vector<string> res = {};
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            string ref = words[i];
            sort(ref.begin(), ref.end());
            res.push_back(words[i]);
            int j = i + 1;
            while(j < n)
            {
                string det = words[j];
                sort(det.begin(), det.end());
                if(det != ref)
                    break;
                j++;
            }
            i = j - 1;
        }

        return res;
    }
};