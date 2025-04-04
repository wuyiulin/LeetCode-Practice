class Solution {
private:
    int DFS(TreeNode*& res, TreeNode* node, int& d, int level)
    {
        if(!node) return level - 1;
        d = max(level, d);
        int l = DFS(res, node->left, d, level + 1);
        int r = DFS(res, node->right, d, level + 1);
        if(l == r && l == d) res = node;
        return max(l, r);
    }
    
public:

    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        int d = 0;
        TreeNode* res = NULL;
        DFS(res, root, d, 0);
        return res;
    }
};

