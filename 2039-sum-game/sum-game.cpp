class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int leftSum=0;
        int rightSum=0;

        int leftQn=0;
        int rightQn=0;

        
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2)leftQn++;
                else rightQn++;
            }else{
                if(i<n/2) leftSum+=num[i]-'0';
                else rightSum+=num[i]-'0';
            }
            
        }
        if((leftQn+rightQn)%2 !=0 )return true;
        
        int l=2*leftSum +9*leftQn;
        int r=2*rightSum +9*rightQn;
        if(l==r)return false;
        else return true;
        
    }
};