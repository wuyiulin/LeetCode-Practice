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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> mp;
        for(const auto& d : descriptions)
            mp[d[0]] = NULL;
        for(const auto& d : descriptions)
        {
            if(mp.find(d[1]) != mp.end())
                mp.erase(d[1]);
        }
        auto it = mp.begin();
        int rootVal = it->first;
        TreeNode* root = new TreeNode(rootVal);
        it->second = root;
        for(const auto& d : descriptions)
        {
            auto itp = mp.find(d[0]);
            auto itc = mp.find(d[1]);
            TreeNode* parent = itp == mp.end() ? new TreeNode(d[0]) : itp->second;
            if(itp == mp.end())
                mp[d[0]] = parent;
            TreeNode* child = itc == mp.end() ? new TreeNode(d[1]) : itc->second;
            if(itc == mp.end())
                mp[d[1]] = child;
            if(d[2])
                parent->left = child;
            else
                parent->right = child;
        }

        return root;
    }
};