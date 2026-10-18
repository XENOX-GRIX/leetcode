class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        int n = nums.size(); 
        int start = 0, ans = 1;
        for(int i = 0; i<n; i++){
            m[nums[i]]++; 
            while(m[nums[i]] > k){
                m[nums[start++]]--;
            }
            ans = max(ans, i - start + 1); 
        }
        return ans; 
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();