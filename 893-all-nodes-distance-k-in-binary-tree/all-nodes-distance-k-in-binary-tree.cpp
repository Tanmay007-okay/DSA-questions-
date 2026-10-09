/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, TreeNode* parent,
                    unordered_map<int, vector<int>>& adj) {
        if (!root) return;

        if (parent) {
            adj[root->val].push_back(parent->val);
            adj[parent->val].push_back(root->val);
        }

        buildGraph(root->left, root, adj);
        buildGraph(root->right, root, adj);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;

        // Step 1: Build the undirected graph
        buildGraph(root, nullptr, adj);

        // Step 2: Initialize BFS
        queue<int> q;
        unordered_set<int> visited;

        q.push(target->val);
        visited.insert(target->val);

        int currLevel = 0;

        // Step 3: Traverse until distance k
        while (!q.empty() && currLevel < k) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            currLevel++;
        }

        // Step 4: Collect nodes at distance k
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};