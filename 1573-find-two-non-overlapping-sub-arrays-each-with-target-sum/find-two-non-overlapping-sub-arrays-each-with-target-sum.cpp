class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> prefixSumToIndex;
        prefixSumToIndex[0] = 0; 
        int cumulativeSum = 0;
        int n = arr.size();
        int minLength[n + 1];
        const int INF = 1 << 30; 
        minLength[0] = INF;
        int result = INF;
        for (int i = 1; i <= n; ++i) {
            int currentValue = arr[i - 1];  
            cumulativeSum += currentValue;
            minLength[i] = minLength[i - 1];
            if (prefixSumToIndex.count(cumulativeSum - target)) {
                int startIndex = prefixSumToIndex[cumulativeSum - target];
                int currentSubarrayLength = i - startIndex;
                minLength[i] = min(minLength[i], currentSubarrayLength);
                result = min(result, minLength[startIndex] + currentSubarrayLength);
            }
            prefixSumToIndex[cumulativeSum] = i;
        }
        return result > n ? -1 : result;
    }
};
