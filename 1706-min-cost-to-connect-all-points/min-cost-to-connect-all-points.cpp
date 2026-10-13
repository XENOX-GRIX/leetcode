class Solution {
public:
    int distance(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]); 
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        vector<int> in_mst(n, 0), dist(n, INT_MAX);
        int ans = 0; 
        dist[0] = 0; 
        // to add n points
        for(int i = 0; i<n; i++){
            int point = -1; 
            // which point to pick 
            for(int j = 0; j<n; j++){
                if(in_mst[j]) continue; 
                if(point == -1 || dist[j] < dist[point]){
                    point = j; 
                }
            }

            // add this point to MST. 
            ans+= dist[point];
            in_mst[point] = 1; 
            for(int j = 0; j<n; j++){
                if(j == point) continue; 
                dist[j] = min(dist[j], distance(points[point], points[j])); 
            }
        }
        return ans;
    }
};