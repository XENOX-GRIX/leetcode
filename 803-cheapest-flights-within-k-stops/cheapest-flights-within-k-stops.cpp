class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> graph[n]; 
        for(auto i : flights){
            graph[i[0]].push_back({i[1], i[2]}); 
        }
        queue<pair<int, int>> q; 
        vector<int> price(n, -1); 
        q.push({src, 0});
        while(!q.empty()){
            if(k < 0) break; 
            int t = q.size(); 
            while(t--){
                auto x = q.front(); 
                q.pop();
                for(auto i : graph[x.first]){
                    if(price[i.first] == -1 ||  price[i.first] > x.second + i.second){
                        price[i.first] =  i.second + x.second; 
                        q.push({i.first, price[i.first]}); 
                    } 
                }
            }
            k--;
        }
        return price[dst]; 
    }
};