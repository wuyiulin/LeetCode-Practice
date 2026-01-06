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
using PII = pair<int, int>;
class Solution {
vector<int> res;
private:
    void mls(TreeNode* root, int level)
    {
        if(level >= res.size())
            res.push_back(0);
        res[level] += root->val;
        if(root->left != nullptr)
            mls(root->left, level + 1);
        
        if(root->right != nullptr)
            mls(root->right, level + 1);
        
        return;
    }
public:
    int maxLevelSum(TreeNode* root) 
    {
        res.resize(1, 0);
        mls(root, 0);

        return max_element(res.begin(), res.end()) - res.begin() + 1;
    }
};