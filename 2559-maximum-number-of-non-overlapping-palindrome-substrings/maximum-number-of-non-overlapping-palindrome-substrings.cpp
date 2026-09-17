class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> is_palindrome(n, vector<int>(n, 0)); 
        for(int i = 0;i<n; i++){
            is_palindrome[i][i] = 1;
        }
        for(int len = 2; len<=k+1; len++){
            for(int start = 0; start <= n - len ; start++){
                int end = start + len - 1; 
                if(len == 2) is_palindrome[start][end] = (s[start] == s[end]); 
                else{
                    is_palindrome[start][end] = (s[start] == s[end]) && (is_palindrome[start+1][end-1]); 
                }
            }
        }

        vector<int> dp(n+1, 0); 

        for(int i = k; i<=n; i++){
            dp[i] = dp[i-1];
            if(i - k >=0 && is_palindrome[i-k][i-1]){
                dp[i] = max(dp[i], 1 + dp[i-k]); 
            }
            if(i - k - 1>=0 && is_palindrome[i-k-1][i-1]){
                dp[i] = max(dp[i], 1 + dp[i-k-1]); 
            }
        }
        return dp[n];
    }
};