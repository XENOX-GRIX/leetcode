class Solution {
public:
    int numberOfSets(int n, int k) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long sum_dp = 0;
            for (int i = 1; i < n; i++) {
                sum_dp = (sum_dp + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i - 1][j] + sum_dp) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};
