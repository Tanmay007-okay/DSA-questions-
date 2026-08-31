class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0,l=0,r=0;
        int n = s.size();
        vector<int> freq(3, 0);
        while(r<n){
            freq[s[r]-'a']++;
            while(freq[0]>0 &&freq[1]>0 && freq[2]>0){
                cnt +=s.length()-r;
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};