class Solution {
public:
    int n, m; 
    int X[4] = {0,0,1,-1}; 
    int Y[4] = {1,-1,0,0}; 
    vector<vector<int>> vis; 
    bool dfs(int x, int y, int pos, vector<vector<char>> &board, string &word){
        if(pos == word.size()) return true;
        vis[x][y] = 1;
        bool ans = false;
        for(int i = 0; i<4; i++){
            int nx = x + X[i];
            int ny = y + Y[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny] || board[nx][ny]!=word[pos]) continue; 
            ans = ans|dfs(nx, ny, pos+1, board, word); 
        }
        vis[x][y] = 0; 
        return ans; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size(); 
        vis = vector<vector<int>>(n, vector<int>(m,0)); 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0] && dfs(i,j,1,board,word)) return true;
            }
        }
        return false; 
    }
};