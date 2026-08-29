class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l=0,r=0;
        int maxf=0;
        int maxlen=0;
        int n=s.length();
        while(r<n){
            freq[s[r]]++;
            maxf=max(maxf,freq[s[r]]);
            if((r-l+1)-maxf>k){
                freq[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
        
    }
};