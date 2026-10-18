class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> graph[n], in(n, 0); 
        queue<int> q; 
        for(auto &i : prerequisites){
            graph[i[1]].push_back(i[0]); 
            in[i[0]]++;    
        }
        for(int i = 0; i<n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t = q.size(); 
            while(t--){
                int course = q.front(); 
                q.pop(); 
                n--;
                for(int i: graph[course]){
                    in[i]--;
                    if(in[i] == 0) q.push(i); 
                }
            }
        }
        return n==0;
    }
};


// [1] -> [0]