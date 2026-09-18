class Solution {
public:
    int findRight(int pos, string &s, vector<int> &first, vector<int> &last){
        int right = last[s[pos]-'a']; 

        for(int i = pos; i<=right; i++){

            if(first[s[i]-'a'] < pos) return -1; 

            right= max(right, last[s[i] - 'a']); 
        }
        return right; 
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, s.size()), last(26, -1); 
        int n = s.size(); 

        for(int i = 0; i<s.size(); i++){
            int pos = s[i] - 'a';
            last[pos] = i; 
            first[pos] = min(i, first[pos]); 
        }

        vector<pair<int, int>> candidates; 

        for(int i = 0; i<n; i++){
            int x = s[i] - 'a'; 
            
            if(first[x] != i) continue; 

            int extremeRight = findRight(i, s, first, last);
            if(extremeRight == -1) continue;  

            if(candidates.size() == 0){
                candidates.push_back({i, extremeRight}); 
            }
            else{
                if(candidates.back().second > i){
                    candidates.pop_back(); 
                }
                candidates.push_back({i, extremeRight}); 
            }
        }
        vector<string> ans; 
        for(auto &[l, r] : candidates){
            ans.push_back(s.substr(l, r-l+1)); 
        }
        return ans;
    }
};