class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(int i=00;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // what if k is still >0 ...remove the k digits from the last of the string
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        string res ="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0')res.pop_back();
        reverse(res.begin(),res.end());
        if(res.empty())return"0";
        return res;

        
    }
};