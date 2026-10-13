class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0, j = 0; 
        int ans = INT_MIN, res = 0; 
        while(j<nums.size()){
            res+=nums[j]; 
            ans = max(ans, res); 
            if(res < 0) res = 0; 
            j++; 
        }
        return ans; 
    }
};