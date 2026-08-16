class Solution {
public:
    string largestOddNumber(string s) {
        int end = -1;
        int i;

        for(i=s.size()-1;i>=0;i--){
            if((s[i]-'0')%2 ==1){
                end =i;
                break;
            }    
        }

        i=0;
        while(i<=end && s[i]=='0') i++;

        return s.substr(i,end-i+1);
        
    }
};