using ll = long long;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> differences(n);
        ll totalSum = 0;
        int maxDiff = 0;
        int totalOperations = k1 + k2;

        for (int i = 0; i < n; ++i) {
            differences[i] = abs(nums1[i] - nums2[i]);
            totalSum += differences[i];
            maxDiff = max(maxDiff, differences[i]);
        }

        if (totalSum <= totalOperations) {
            return 0;
        }

        int left = 0;
        int right = maxDiff - 1;
        int firstTrueIndex = maxDiff; 

        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll operationsNeeded = 0;

            for (int val : differences) {
                operationsNeeded += max(val - mid, 0);
            }

            if (operationsNeeded <= totalOperations) {
                // Feasible: can achieve this threshold
                firstTrueIndex = mid;
                right = mid - 1;  // Try to find smaller threshold
            } else {
                left = mid + 1;
            }
        }

        int optimalThreshold = firstTrueIndex;

        for (int i = 0; i < n; ++i) {
            int reduction = max(0, differences[i] - optimalThreshold);
            totalOperations -= reduction;
            differences[i] = min(differences[i], optimalThreshold);
        }

        for (int i = 0; i < n && totalOperations > 0; ++i) {
            if (differences[i] == optimalThreshold) {
                --totalOperations;
                --differences[i];
            }
        }
        ll result = 0;
        for (int val : differences) {
            result += 1ll * val * val;
        }

        return result;
    }
};
