class Solution {
public:
    void helper(int ind,string digits,string s,vector<string>& ans,string combos[]){
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        } 
        // '2'->2
        int digit = digits[ind]- '0';
        for(int i=0;i<combos[digit].size();i++){
            helper(ind+1,digits,s+combos[digit][i],ans,combos);
        }
    }
    vector<string> letterCombinations(string digits) {

        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; 
        string s = ""; 
        helper(0, digits, s, ans, combos);
        return ans;
    }
};