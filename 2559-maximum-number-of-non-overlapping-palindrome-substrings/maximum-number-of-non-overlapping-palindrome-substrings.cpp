class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        vector<int> memo(n, -1);
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start + 1; end < n; ++end) {

                isPalindrome[start][end] =
                    (s[start] == s[end]) && isPalindrome[start + 1][end - 1];
            }
        }

        function<int(int)> findMaxPalindromes = [&](int startIdx) -> int {

            if (startIdx >= n) {
                return 0;
            }
            if (memo[startIdx] != -1) {
                return memo[startIdx];
            }

            int maxCount = findMaxPalindromes(startIdx + 1);

            for (int endIdx = startIdx + k - 1; endIdx < n; ++endIdx) {
                if (isPalindrome[startIdx][endIdx]) {

                    maxCount =
                        max(maxCount, 1 + findMaxPalindromes(endIdx + 1));
                }
            }
            memo[startIdx] = maxCount;
            return maxCount;
        };

        return findMaxPalindromes(0);
    }
};
