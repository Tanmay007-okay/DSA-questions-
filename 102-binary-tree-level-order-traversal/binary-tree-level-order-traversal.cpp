/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void levelord(vector<vector < int >> &ans, TreeNode* root, int lev) {
        if (root == nullptr)
            return;
        if (ans.size() < lev + 1)
            ans.push_back(vector<int>());
        ans[lev].push_back(root->val);
        levelord(ans, root->left, lev + 1);
        levelord(ans, root->right, lev + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelord(ans,root,0);
        return ans;
    }
};