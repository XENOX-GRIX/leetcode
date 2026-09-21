struct box{
    int x; 
    int y; 
    int e;
    int m; 
}; 

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(); 
        int m = classroom[0].size(); 
        int l = 0, x = 0, y = 0;
        int X[4] = {0,0,1,-1}; 
        int Y[4] = {1,-1,0,0};
        int ans = 0; 
        vector<vector<int>> litter(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(classroom[i][j] == 'L'){
                    litter[i][j] = l; 
                    l++; 
                }
                if(classroom[i][j] == 'S'){
                    x = i; 
                    y = j; 
                }
            }
        }
        int fullMask = (1 << l) - 1;
        vector<vector<vector<int>>> best(n, vector<vector<int>>(m, vector<int>(1<<l, -1))); 

        queue<box> q; 
        q.push({x, y, energy, 0}); 
        best[x][y][0] = energy; 
        while(q.size()){
            int t = q.size(); 
            while(t--){
                auto top = q.front(); 
                q.pop(); 
                if(top.m == fullMask) return ans; 
                if(top.e == 0) continue; 

                for(int i = 0; i<4; i++){
                    x = top.x + X[i]; 
                    y = top.y + Y[i]; 

                    if(x<0 || y<0 || x >= n || y>=m) continue; 
                    
                    if(classroom[x][y] == 'X') continue; 
                    int ne = top.e - 1, mask = top.m ; 
                    

                    if (classroom[x][y] == 'R') {
                        ne = energy;
                    }

                    if (classroom[x][y] == 'L') {
                        int id = litter[x][y];
                        mask |= (1 << id);
                    }

                    if (best[x][y][mask] >= ne){
                        continue;
                    }

                    best[x][y][mask] = ne;

                    q.push({x, y, ne, mask});
                }
            }
            ans++; 
        }
        return -1;

    }
};