class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int> s;
        for(int i=0;i<n;i++){
            if(digits[i]==0)continue; //10oth place cannot be 0.
            for(int j=0;j<n;j++){
                if(j==i)continue;//no repeatition .
                for(int k=0;k<n;k++){
                    if(k==i ||k==j)continue;//no repeat.
                    if(digits[k]%2==0){
                        int num=digits[i]*100+digits[j]*10+digits[k];
                        s.insert(num);
                    }
                }
            }
        }
        return s.size();
             
    }
};