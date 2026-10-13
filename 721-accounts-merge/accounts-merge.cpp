class Solution {
public:
    vector<int> parent; 
    unordered_map<int, set<string>> m_st; 

    int find(int i){
        if(i == parent[i]) return i; 
        return parent[i] = find(parent[i]); 
    }

    void unite(int i, int j){
        int fi = find(i); 
        int fj = find(j); 
        
        if (fi == fj) return;  
        
        if (m_st[fi].size() < m_st[fj].size()){
            parent[fi] = fj;
            for(auto& x : m_st[fi]){
                m_st[fj].insert(std::move(x));
            }
            m_st[fi].clear();
        } else {
            parent[fj] = fi;
            for(auto& x : m_st[fj]){
                m_st[fi].insert(std::move(x));
            }
            m_st[fj].clear();
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size(); 
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        
        m_st.clear();
        parent = vector<int>(n, 0); 

        for(int i = 0; i < n; i++){
            parent[i] = i; 
            for(int j = 1; j < accounts[i].size(); j++){
                m_st[i].insert(accounts[i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                auto id = accounts[i][j]; 
                if(m.find(id) != m.end()){
                    unite(m[id], i);
                }
                m[id] = i;
            }
        }

        for(int i = 0; i < n; i++){
            int root = find(i); 
            if(root == i && !m_st[i].empty()){
                vector<string> temp;
                temp.push_back(accounts[i][0]); 
                for(const auto& email : m_st[i]){
                    temp.push_back(email);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};