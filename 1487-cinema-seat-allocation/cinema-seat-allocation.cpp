class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& v) {
        sort(v.begin(), v.end()); 
        int ans = n*2;
        int nn = v.size();
        for(int i = 0; i<v.size(); i++){
            int row = v[i][0]; 
            int f25 = 1, f47 = 1, f69 = 1; 
            while(i<nn && v[i][0] == row){
                if(v[i][1] >=2 && v[i][1] <=5) f25 = 0; 
                if(v[i][1] >=4 && v[i][1] <=7) f47 = 0; 
                if(v[i][1] >=6 && v[i][1] <=9) f69 = 0; 
                i++; 
            }
            i--; 
            // check the number of blocks available.
            if(f25 + f47 + f69 == 0) ans-=2; 
            else if(f25 && f69) continue; 
            else if(f25 || f69 || f47){
                ans-=1; 
            }
            // if(f47 == 0) ans--;
            cout<<row<<" "<<ans<<endl;
        }
        return ans;
    }
};