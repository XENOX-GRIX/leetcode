class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0 ;
        for(int &i: nums){
            sum+= i; 
        }
        long long currSum = 0, res = sum - x;
        int len = -1, prevIndex = 0, n = nums.size(); 
        for(int i = 0; i<n; i++){
            currSum+= nums[i]; 
            while(currSum > res && prevIndex<=i){
                currSum-=nums[prevIndex++]; 
            }
            if(currSum == res) len = max(len, i - prevIndex + 1); 
        } 
        return len == -1 ? len : n - len; 
    }
};