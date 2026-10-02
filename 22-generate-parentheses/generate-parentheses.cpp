class Solution {
public:
    void help(string curr,int open,int close,int n,vector<string> &res){
        if(curr.length() ==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n) help(curr+'(',open+1,close,n,res);
        if(close<open) help(curr+')',open,close+1,n,res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        help("",0,0,n,res);
        return res;
    }
};