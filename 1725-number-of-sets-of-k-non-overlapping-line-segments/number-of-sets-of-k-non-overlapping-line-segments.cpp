class Solution {
public:

    int dp[1010][1010];

    int endingAt[1010][1010];
  
    const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {

        memset(dp, 0, sizeof(dp));
        memset(endingAt, 0, sizeof(endingAt));

        dp[1][0] = 1;

        for (int points = 2; points <= n; ++points) {
            for (int segments = 0; segments <= k; ++segments) {
 
                dp[points][segments] = (dp[points - 1][segments] + endingAt[points - 1][segments]) % MOD;

                endingAt[points][segments] = endingAt[points - 1][segments];
              
                if (segments > 0) {

                    endingAt[points][segments] = (endingAt[points][segments] + dp[points - 1][segments - 1]) % MOD;

                    endingAt[points][segments] = (endingAt[points][segments] + endingAt[points - 1][segments - 1]) % MOD;
                }
            }
        }

        return (dp[n][k] + endingAt[n][k]) % MOD;
    }
};
