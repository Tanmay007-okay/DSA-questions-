#include <bits/stdc++.h>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int x) {
//         val = x;
//         left = nullptr;
//         right = nullptr;
//     }
// };

class Solution {
private:
    // Returns the best path starting
    // here and moving through one child.
    int findMaxDownwardPath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Negative branches are ignored
        // because they reduce the path sum.
        int leftGain = max(
            0,
            findMaxDownwardPath(root->left)
        );

        // Negative branches are ignored
        // because they reduce the path sum.
        int rightGain = max(
            0,
            findMaxDownwardPath(root->right)
        );

        // Only one branch can continue
        // as a downward path.
        return root->val + max(
            leftGain,
            rightGain
        );
    }

public:
    // Finds the best path by considering
    // every node as a turning point.
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return INT_MIN;
        }

        // Negative contributions are skipped
        // while forming the current path.
        int leftContribution = max(
            0,
            findMaxDownwardPath(root->left)
        );

        int rightContribution = max(
            0,
            findMaxDownwardPath(root->right)
        );

        // Both branches may participate when
        // this node is the path's turning point.
        int currentPath =
            root->val
            + leftContribution
            + rightContribution;

        // The best path may lie completely
        // inside either subtree.
        int leftBest = root->left
            ? maxPathSum(root->left)
            : INT_MIN;

        int rightBest = root->right
            ? maxPathSum(root->right)
            : INT_MIN;

        return max({
            currentPath,
            leftBest,
            rightBest
        });
    }
};

