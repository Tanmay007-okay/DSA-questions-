class Solution {
  // Each node stores the product of the whole segment modulo k
  // and the number of prefixes for every possible remainder.
  struct Node {
    int prod = 1;
    array<int, 5> cnt{};
  };

  int n, k;
  vector<Node> tree;

  // Merge two adjacent segments.
  // Keep all prefixes from the left segment.
  // Prefixes from the right segment are multiplied by the full left product.
  Node mergeNodes(const Node& left, const Node& right) {
    Node res;
    res.prod = (left.prod * right.prod) % k;

    for(int r = 0; r < k; r++) res.cnt[r] += left.cnt[r];

    for(int r = 0; r < k; r++) {
      int nr = (left.prod * r) % k;
      res.cnt[nr] += right.cnt[r];
    }

    return res;
  }

  // Build the segment tree.
  // A leaf has exactly one non-empty prefix: the element itself.
  void build(int node, int l, int r, const vector<int>& nums) {
    if(l == r) {
      int rem = nums[l] % k;
      tree[node].prod = rem;
      tree[node].cnt[rem] = 1;

      return;
    }

    int mid = l + (r - l) / 2;

    build(node * 2, l, mid, nums);
    build(node * 2 + 1, mid + 1, r, nums);

    tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
  }

    // Permanently update nums[index] and rebuild the affected tree nodes.
  void update(int node, int l, int r, int index, int value) {
    if(l == r) {
      tree[node] = Node{};

      int rem = value % k;
      tree[node].prod = rem;
      tree[node].cnt[rem] = 1;

      return;
    }

    int mid = l + (r - l) / 2;

    if(index <= mid) update(node * 2, l, mid, index, value);
    else update(node * 2 + 1, mid + 1, r, index, value);

    tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
  }

  // Return the combined information for range [ql, qr].
  // For each query this range is [start, n - 1].
  Node query(int node, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree[node];

    int mid = l + (r - l) / 2;

    if(qr <= mid) return query(node * 2, l, mid, ql, qr);
    if(ql > mid) return query(node * 2 + 1, mid + 1, r, ql, qr);

    Node left = query(node * 2, l, mid, ql, qr);
    Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

    return mergeNodes(left, right);
  }

public:
  vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
    this->n = nums.size();
    this->k = k;

    // Build the tree for the initial array.
    tree.resize(4 * n);
    build(1, 0, n - 1, nums);

    vector<int> result;
    result.reserve(queries.size());

    // Apply each permanent update, then analyze nums[start..n - 1].
    for(const auto& q : queries) {
      int index = q[0];
      int value = q[1];
      int start = q[2];
      int x = q[3];

      update(1, 0, n - 1, index, value);

      // cnt[x] is the number of prefixes of nums[start..n - 1]
      // whose product modulo k equals x.
      Node res = query(1, 0, n - 1, start, n - 1);
      result.push_back(res.cnt[x]);
    }

    return result;
  }
};