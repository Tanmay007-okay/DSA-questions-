class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
      
        // Build adjacency list for the tree (children for each node)
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
      
        // Track the stack of ancestors for each character (a-z)
        // ancestors[i] contains the stack of nodes with character 'a' + i
        vector<vector<int>> ancestors(26);
      
        // Result array to store subtree sizes
        vector<int> subtreeSizes(n);
      
        // DFS function to traverse the tree and calculate subtree sizes
        auto dfs = [&](this auto&& dfs, int node, int parentNode) -> void {
            // Initialize current node's subtree size to 1 (itself)
            subtreeSizes[node] = 1;
          
            // Get the character index (0-25 for 'a'-'z')
            int charIndex = s[node] - 'a';
          
            // Add current node to the ancestor stack for this character
            ancestors[charIndex].push_back(node);
          
            // Recursively process all children
            for (int child : children[node]) {
                dfs(child, node);
            }

            int nearestAncestor = ancestors[charIndex].size() > 1 ? 
                                  ancestors[charIndex][ancestors[charIndex].size() - 2] : 
                                  parentNode;
          
            if (nearestAncestor >= 0) {
                subtreeSizes[nearestAncestor] += subtreeSizes[node];
            }
            ancestors[charIndex].pop_back();
        };
        dfs(0, -1);
      
        return subtreeSizes;
    }
};
