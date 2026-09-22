class Solution {
public:
    bool isPalindrome(string &s){
        int a = 0, b = s.size()-1; 
        while(a<b){
            if(s[a] != s[b]) return false; 
            a++; b--; 
        }
        return true; 
    }
    int maxPalindromes(string s, int k) {
        int n = s.size(); 
        vector<int> dp(n+1, 0); 
        for(int i = k; i<=n; i++){
            string x0 = s.substr(i - k, k);
            dp[i] = dp[i-1]; 

            if(isPalindrome(x0)){
                dp[i] = max(dp[i], 1 + dp[i - k]); 
            }
            if(i - k - 1 >= 0){
                x0 = s.substr(i - k - 1, k+1); 
                if(isPalindrome(x0)){
                    dp[i] = max(dp[i], 1 + dp[i - k-1]); 
                }
            }
        }
        return dp[n]; 
    }
};