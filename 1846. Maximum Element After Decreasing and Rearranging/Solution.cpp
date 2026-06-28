class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 1;
        sort(arr.begin(), arr.end());

        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] > ans)
                ans++;
        }
        return ans;
    }
};