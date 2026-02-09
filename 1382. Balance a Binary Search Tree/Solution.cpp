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
vector<int> nodes;
private:
    void inOrder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);

        return;
    }
    TreeNode* buildBT(int start, int end) {
        if (start > end) 
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);

        node->left = buildBT(start, mid - 1);
        node->right = buildBT(mid + 1, end);

        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        nodes.clear();
        inOrder(root);

        return buildBT(0, nodes.size() - 1);
    }
};