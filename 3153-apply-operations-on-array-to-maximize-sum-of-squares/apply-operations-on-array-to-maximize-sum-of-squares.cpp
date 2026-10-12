class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32,0); 
        long long ans = 0; 
        int mod = 1e9 + 7;
        for(int i : nums){
            int pos = 0; 
            while(i){
                bits[pos++]+= i%2; 
                i/=2;
            }
        }
        while(k--){
            long long num = 0; 
            for(int i = 0; i<32; i++){
                if(bits[i]){
                    bits[i]--;
                    num=(num+(1ll<<i));
                }
            }
            num = (num*num)%mod; 
            ans = (ans + num)%mod; 
        }
        return ans; 
    }
};

