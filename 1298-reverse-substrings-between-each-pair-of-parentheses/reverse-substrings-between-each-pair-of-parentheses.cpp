class Solution {
public:
    string reverseParentheses(string s) {
        string st;
        for(char& ch :s){
            if(ch==')'){
                string temp;
                while(st.back() != '('){
                    temp.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back();//removes (
                st +=temp;
            }else{
                st.push_back(ch);
            }
        }
        return st;
        
    }
};