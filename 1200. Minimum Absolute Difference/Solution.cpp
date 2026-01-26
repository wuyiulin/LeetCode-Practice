class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        int minVal = INT_MAX, n = arr.size();
        vector<vector<int>> res = {};
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++)
        {
            if((arr[i + 1] - arr[i]) == minVal)
            {
                res.push_back({arr[i], arr[i + 1]});   
            }
            else if((arr[i + 1] - arr[i]) < minVal)
            {
                minVal = arr[i + 1] - arr[i];
                res = {};
                res.push_back({arr[i], arr[i + 1]});
            }
        }

        return res;
    }
};