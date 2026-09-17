class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), running_sum = 0, prev = 0, MAX_ = 1e5+1; 
        vector<int> pre(n, MAX_), suff(n, MAX_);    
        for(int i = 0; i<n; i++){
            running_sum+=arr[i]; 
            while(prev<i && running_sum > target){
                running_sum-=arr[prev]; 
                prev++; 
            }
            if(target == running_sum) pre[i] = min((i==0?MAX_:pre[i-1]), i - prev + 1); 
            else pre[i] = i==0?pre[i]:pre[i-1]; 
        }
        running_sum = 0;
        prev = n - 1; 
        for(int i = n-1; i>=0; i--){
            running_sum+=arr[i]; 
            while(prev > i && running_sum > target){
                running_sum-=arr[prev]; 
                prev--; 
            }
            if(target == running_sum) suff[i] = min((i==n-1?MAX_:suff[i+1]), prev - i + 1); 
            else suff[i] = i==n-1?suff[n-1]:suff[i+1]; 
        }

        int ans = MAX_;
        for(int i = 0; i<n-1; i++){
            ans = min(ans, pre[i] + suff[i+1]);
        }
        return ans==MAX_?-1:ans; 
    }
};