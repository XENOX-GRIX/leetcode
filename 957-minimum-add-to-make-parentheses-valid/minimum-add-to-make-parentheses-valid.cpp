class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st; 
        for(char i : s){
            if(i == ')'){
                if(st.empty() || st.top() == ')') st.push(i); 
                else st.pop(); 
            }
            else{
                st.push(i);
            }
        }
        return (int)st.size();
    }
};