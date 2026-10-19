class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans; 
        int n = strs.size(); 
        for(int i = 0; i<n; i++){
            string x = strs[i];
            sort(x.begin(), x.end());
            m[x].push_back(strs[i]); 
        } 
        for(auto [k,v]: m){
            ans.push_back(v); 
        }
        return ans;
    }
};