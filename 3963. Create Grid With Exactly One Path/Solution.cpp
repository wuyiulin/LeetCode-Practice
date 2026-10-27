class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        for(auto& s : res)  
            s[0] = '.';
        res.back().assign(n, '.');

        return res;
    }
};
