class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; 
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || st.empty()) {
                st.push(i);
                continue; 
            }
            if(s[st.top()]=='(') st.pop(); 
            else st.push(i); 
        }
        if(st.size()==0) return s.size(); 
        int t = s.size(); 
        int ans = 0; 
        while(st.size()){
            int p = st.top(); 
            st.pop(); 
            ans = max(ans, t - p - 1); 
            t = p; 
        }
        return max(ans,t); 
    }
};