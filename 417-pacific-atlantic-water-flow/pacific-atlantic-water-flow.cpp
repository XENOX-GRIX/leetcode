class Solution {
public:
    int X[4] = {0,0,1,-1}; 
    int Y[4] = {1,-1,0,0}; 
    int n, m; 
    void dfs(int x, int y, vector<vector<int>> &mask,vector<vector<int>> &heights){
        mask[x][y] = 1; 
        for(int i = 0; i<4; i++){
            int nx = x + X[i]; 
            int ny = y + Y[i]; 
            if(nx>=0 && ny>=0 && nx<n && ny<m && !mask[nx][ny] && heights[nx][ny]>=heights[x][y]){
                dfs(nx, ny, mask, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(); 
        m = heights[0].size(); 
        vector<vector<int>> p(n, vector<int>(m,0));
        vector<vector<int>> a(n, vector<int>(m,0));
        vector<vector<int>> ans; 
        for(int i = 0; i<n; i++){
            dfs(i, 0, p, heights);
            dfs(i, m-1, a, heights); 
        }
        for(int i = 0; i<m; i++){
            dfs(0,i, p, heights);
            dfs(n-1, i, a, heights); 
        }
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a[i][j] && p[i][j]){
                    ans.push_back({i,j}); 
                }
            }
        }
        return ans;
    }
};