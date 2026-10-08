class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for(char ch:s){
            if(ch=='('){
                if(!st.empty())ans+=ch;//for i=0 '(' does'nt goes to the ans as stack is empty at that point.
                st.push(ch);
            }else{
                st.pop();
                if(!st.empty())ans+=ch;
            }
        } 
        return ans;     
    }
};