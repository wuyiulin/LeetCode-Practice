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
class Solution 
{
public:
    int sumRootToLeaf(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;

        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            auto [node, val] = q.front();
            q.pop();

            int curr = (val << 1) | node->val;

            if(node->left == nullptr && node->right == nullptr)
            {
                res += curr;
            }

            if(node->left != nullptr)
            {
                q.push({node->left, curr});
            }

            if(node->right != nullptr)
            {
                q.push({node->right, curr});
            }
        }

        return res;
    }
};