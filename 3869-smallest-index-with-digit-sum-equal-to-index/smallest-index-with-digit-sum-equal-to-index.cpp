class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
            int x = nums[i], count = 0;
            while(x){
                count+=(x%10); 
                x/=10;
            } 
            if(count == i) return i; 
        }
        return -1; 
    }
};