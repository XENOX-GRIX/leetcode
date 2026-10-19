class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return ""; 
        unordered_map<char, int> freq;
        int i = 0, j = 0, length = INT_MAX,  pos = -1, count = 0; 
        for(char x : t){
            freq[x]++; 
        }
        count = freq.size(); 
        for(int i = 0; i<s.size(); i++){
            if(freq.find(s[i])!=freq.end()){
                freq[s[i]]--;
                if(freq[s[i]] == 0){
                    count--; 
                }
            }
            while(count==0){
                int l = i - j + 1; 
                if(l < length){
                    pos = j; 
                    length = l; 
                }
                if(freq.find(s[j])!=freq.end()){
                    freq[s[j]]++; 
                    if(freq[s[j]] > 0) count++;  
                }
                j++;
            }
        }
        if(pos==-1){
            return "";
        }
        return s.substr(pos, length); 
    }
};