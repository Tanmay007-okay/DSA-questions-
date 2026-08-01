class Solution {
    public int countPrimes(int n) {
        if (n < 2) return 0;

        boolean[] isNotPrime = new boolean[n];
        int count = 0;

        for (int i = 2; i < n; i++) {
            // If i is prime
            if (!isNotPrime[i]) {
                count++;
                
                // Mark multiples starting from i * i
                for (long k = (long) i * i; k < n; k += i) {
                    isNotPrime[(int) k] = true;
                }
            }
        }

        return count;
    }
}