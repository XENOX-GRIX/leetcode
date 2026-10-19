class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ; 
        priority_queue<int, vector<int>, greater<int>> q; 
        for(int i = 0; i<prices.size(); i++){
            if(!q.empty()){
                if(q.top()<prices[i]){
                    ans = max(ans, prices[i] - q.top()); 
                }
            }
            q.push(prices[i]); 
        }
        return ans;
    }
};