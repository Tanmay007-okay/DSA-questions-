class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count[2] = {1, 0};
      
        int result = 0;
        int prefixSum = 0;
      
        for (int num : arr) {
            prefixSum += num;
            int parityNeeded = (prefixSum & 1) ^ 1;
            result = (result + count[parityNeeded]) % MOD;
            int currentParity = prefixSum & 1;
            ++count[currentParity];
        }
      
        return result;
    }
};
