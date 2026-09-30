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
    int maxDepth(TreeNode*root){
        if(root==nullptr)return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
    int findDiameter(TreeNode* root){
        if(root==nullptr)return 0;
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int currentDiameter=leftHeight+rightHeight;

        int leftDiameter=findDiameter(root->left);
        int rightDiameter=findDiameter(root->right);

        return max(currentDiameter,max(leftDiameter,rightDiameter));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return findDiameter(root);
    }
};