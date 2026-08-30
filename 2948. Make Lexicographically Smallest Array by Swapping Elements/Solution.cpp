class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idxs(n), res(n, 0);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        int i = 0;
        while(i<n)
        {
            int j = i;
            while(j+1<n && nums[idxs[j+1]] - nums[idxs[j]] <= limit)
                j++;
            vector<int> pos(idxs.begin() + i, idxs.begin() + j + 1);
            sort(pos.begin(), pos.end());
            int ps = pos.size();
            for(int k=0; k<ps; k++)
                res[pos[k]] = nums[idxs[i + k]];
            i = j + 1;
        }


        return res;
    }
};