class FindSumPairs {
unordered_map<int, int> m1, m2;
vector<int> nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        for(const int& i : nums1)
            m1[i]++;
        for(const int& i : nums2)
            m2[i]++;
        this->nums2 = nums2;
    }
    
    void add(int index, int val) 
    {
        if(!val)
            return;
        int oldKey = nums2[index];
        int newKey = oldKey + val;
        m2[oldKey]--;
        m2[newKey]++;
        nums2[index] = newKey;
    }
    
    int count(int tot) 
    {
        int cnt = 0;
        for(auto& [key, val1] : m1)
        {
            int tar = tot - key;
            if(m2.count(tar))
            {
                cnt += (val1 * m2[tar]);
            }
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */