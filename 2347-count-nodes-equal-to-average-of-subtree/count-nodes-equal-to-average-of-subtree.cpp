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
    int averageOfSubtree(TreeNode* root) {
        int count = 0; 
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> pair<int, int> {
            
            if (!node) {
                return {0, 0};
            }
            auto [leftSum, leftCount] = dfs(node->left);
          
            auto [rightSum, rightCount] = dfs(node->right);
          
            int subtreeSum = leftSum + rightSum + node->val;
            int subtreeCount = leftCount + rightCount + 1;
            if (subtreeSum / subtreeCount == node->val) {
                ++count;
            }
            return {subtreeSum, subtreeCount};
        };

        dfs(root);
      
        return count;
    }
};
