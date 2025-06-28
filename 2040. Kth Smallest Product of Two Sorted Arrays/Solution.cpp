class Solution {
using LL = long long;
private:
    void sp(vector<int>& nums, vector<int>& v1, vector<int>& v2)
    {
        for(const auto& num : nums)
        {
            if(num < 0)
                v1.push_back(-num);
            else
                v2.push_back(num);
        }
        reverse(v1.begin(), v1.end());
    }

    LL getCnt(vector<int>& A, vector<int>& B, LL m)
    {
        LL cnt = 0;
        int j = B.size() - 1;
        for(const LL& a : A)
        {
            while(j >= 0 && a * B[j] > m)
                j--;
            cnt += (j + 1);
        }

        return cnt;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        vector<int> A1, A2, B1, B2;
        sp(nums1, A1, A2);
        sp(nums2, B1, B2);
        const LL nCnt = A1.size() * B2.size() + A2.size() * B1.size();
        int sign = 1;
        if(k > nCnt)
            k -= nCnt;
        else
        {
            k = nCnt - k + 1;
            sign = -1;
            swap(B1, B2);
        }

        LL l = 0, r = 1e10;
        while(l < r)
        {
            const LL m = l + (r - l)/2;
            if(getCnt(A1, B1, m) + getCnt(A2, B2, m) >= k)
                r = m;
            else
                l = m + 1;
        }

        return sign * l;
    }
};