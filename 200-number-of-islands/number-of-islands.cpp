class Solution {
public:
    int n, m; 
    int X[4] = {0,0,1,-1}; 
    int Y[4] = {1,-1,0,0}; 
    void dfs(int x, int y, vector<vector<char>> &grid){
        grid[x][y] = '0';
        for(int i = 0; i<4; i++){
            int n_x = x + X[i]; 
            int n_y = y + Y[i]; 
            if(n_x >= 0 && n_y >=0 && n_x <n && n_y<m && grid[n_x][n_y] == '1'){
                dfs(n_x, n_y, grid); 
            }
        } 
    }

    int numIslands(vector<vector<char>> grid) {
        int ans = 0; 
        n = grid.size(); 
        m = grid[0].size(); 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid); 
                    ans++;
                }
            }
        }
        return ans;
    }
};