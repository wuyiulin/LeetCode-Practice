class Solution {
private:
    void helper(vector<double>& arr, double& diff, bool& res)
    {
        if(res)
            return;
        if(arr.size() == 1)
        {
            if(abs(arr[0] - 24) < diff)
                res = true;
            
            return;
        }
        int as = arr.size();
        for(int i=0; i<as; i++)
        {
            for(int j=0; j<i; j++)
            {
                double p = arr[i], n = arr[j];
                vector<double> tmp = {p+n, p-n, n-p, p*n};
                if(p > diff)
                    tmp.push_back(n/p);
                if(n > diff)
                    tmp.push_back(p/n);
                arr.erase(arr.begin() + i);
                arr.erase(arr.begin() + j);
                for(auto t : tmp)
                {
                    arr.push_back(t);
                    helper(arr, diff, res);
                    arr.pop_back();
                }
                
                arr.insert(arr.begin() + j, n);
                arr.insert(arr.begin() + i, p);
            }
        }

        return;
    }

public:
    bool judgePoint24(vector<int>& cards) 
    {
        vector<double> arr(cards.begin(), cards.end());
        double diff = 1e-5;
        bool res = false;
        helper(arr, diff, res);

        return res;
    }
};