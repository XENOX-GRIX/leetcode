class Solution {
public:
    int maximalSquare(vector<vector<char>>& dp) {
        int n= dp.size(), m=dp[0].size(); 
        int ans=0; 
        vector<vector<int>> mat(n, vector<int>(m,0)); 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[i][j]=dp[i][j]-'0';
                if(mat[i][j]==1){
                    ans=max(ans,1); 
                    if(i==0 || j==0) continue; 
                    if(mat[i-1][j-1] && mat[i-1][j] && mat[i][j-1]){
                        mat[i][j]+=min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1])); 
                        ans=max(mat[i][j],ans);
                    }
                }
                
            }
        }
        return ans*ans;
    }
};