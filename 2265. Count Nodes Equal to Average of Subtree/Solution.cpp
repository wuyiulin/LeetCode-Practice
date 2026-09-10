/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int, int> dfs(TreeNode* root, int& res)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            res++;
            return {root->val, 1};
        }
        const auto [left, lcnt] = root->left != nullptr ? dfs(root->left, res) : pair<int, int>{0, 0};
        const auto [right, rcnt] = root->right != nullptr ? dfs(root->right, res) : pair<int, int>{0, 0};
        int val = left + right + root->val, cnt = lcnt + rcnt + 1;
        if(val / cnt == root->val)
            res++;

        return {val, cnt};

    }
public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);

        return res;
    }
};