class Solution {
public:
    bool match(int is, int jp, string &s, string &p){
        if(jp < 0) return is < 0; 

        if(jp > 0 && p[jp] == '*'){
            // lets skip this 
            if(match(is, jp -2, s, p)) return 1; 
            // use 1 or more time
            if(is >= 0 && (s[is] == p[jp-1] || p[jp-1] == '.')){
                return match(is - 1, jp, s, p);
            }
            return false; 
        }

        if(is>=0 && (s[is] == p[jp] || p[jp] == '.')) return match(is-1, jp-1, s, p); 
        return false;

    }
    bool isMatch(string s, string p) {
        int ns = s.size(); 
        int np = p.size(); 
        
        return match(ns-1, np-1, s, p); 

    }
};