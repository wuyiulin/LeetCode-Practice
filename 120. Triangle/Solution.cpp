class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        for(int row=n-2; row>=0; row--)
        {
            for(int col=0; col<triangle[row].size(); col++)
            {
                int l = INT_MAX, r = INT_MAX;
                r = triangle[row + 1][col + 1];
                l = triangle[row + 1][col];
                
                triangle[row][col] += min(l, r);
            }
        }

        return triangle[0][0];
    }
};