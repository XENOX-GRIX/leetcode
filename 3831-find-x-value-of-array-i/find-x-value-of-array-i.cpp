class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);
        for(int i = 0; i<nums.size(); i++){
            vector<long long> v(k);
            int x = nums[i]%k;
            v[x]++;
            for(int j = 0; j<k; j++){
                v[(x * j) % k] += dp[j];
            }
            for(int j = 0; j<k; j++){
                ans[j]+=v[j]; 
            }
            dp = v;
        }
        return ans;   
    }
};