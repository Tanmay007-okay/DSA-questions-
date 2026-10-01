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
    int findMaxGain(TreeNode* root,int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        // Negative branches are ignored
        // because they reduce the path sum.
        int leftGain = max(
            0,
            findMaxGain(root->left,maxSum)
        );

        // Negative branches are ignored
        // because they reduce the path sum.
        int rightGain = max(
            0,
            findMaxGain(root->right,maxSum)
        );
        int currentPath=root->val+leftGain+rightGain;
        maxSum=max(maxSum,currentPath);
        // Only one branch can continue
        return root->val + max(
            leftGain,
            rightGain
        );
    }

public:
    // Finds the best path by considering
    // every node as a turning point.
    int maxPathSum(TreeNode* root) {
       int maxSum=INT_MIN;
       findMaxGain(root,maxSum);
       return maxSum;
    }
};

