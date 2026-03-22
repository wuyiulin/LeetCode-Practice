class Solution {
private:
    void clockwise(vector<vector<int>>& mat)
    {
        int row = mat.size(), col = mat[0].size();
        for(int i=0; i<row; i++)
            for(int j=0; j<col/2; j++)
                swap(mat[i][j], mat[i][col - j - 1]);
        for(int i=0; i<row; i++)
            for(int j=i+1; j<col; j++)
                swap(mat[i][j], mat[j][i]);
        return;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        bool f = false;

        for(int i=0; i<4; i++)
        {
            if(i)
                clockwise(mat);
            if(mat == target)
            {
                f = true;
                break;
            }
        }

        return f;
    }
};