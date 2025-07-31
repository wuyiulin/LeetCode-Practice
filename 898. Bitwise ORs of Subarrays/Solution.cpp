class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_set<int> res, prev;
        for(const auto& num : arr)
        {
            unordered_set<int> curr;
            curr.insert(num);
            for(const auto& p : prev)
                curr.insert(p|num);
            prev = curr;
            for(const auto& c : curr)
                res.insert(c);
        }

        return res.size();
    }
};