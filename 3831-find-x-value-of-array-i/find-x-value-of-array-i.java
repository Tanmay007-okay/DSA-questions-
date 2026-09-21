class Solution {
  public long[] resultArray(int[] nums, int k) {
    long[] result = new long[k];
    long[] dp = new long[k];

    for(int num : nums) {
      long[] next = new long[k];
      int value = num % k;

      // Start a new subarray.
      next[value]++;

      // Extend all subarrays ending at the previous position.
      for(int r = 0; r < k; r++) {
        int newRemainder = (r * value) % k;
        next[newRemainder] += dp[r];
      }

      for(int r = 0; r < k; r++) result[r] += next[r];

      dp = next;
    }

    return result;
  }
}