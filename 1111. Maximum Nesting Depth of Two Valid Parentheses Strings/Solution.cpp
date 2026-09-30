class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int layer = 0, n = seq.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; i++)
        {
            if(seq[i] == '(')
            {
                layer++;
                res[i] = (layer % 2);
            }
            else
            {
                res[i] = (layer % 2);
                layer--;
            }
        }

        return res;
    }
};