class Solution {
public:
    int divide(int dividend, int divisor) {
        long long sum=0;
        if(dividend == divisor) return 1;
    //    to avoid integer overflow
        if(dividend ==INT_MIN && divisor ==-1) return INT_MAX;
        if(divisor==1)return dividend;
        bool positive=true;
        if(dividend >=0 && divisor <0) positive=false;
        else if(dividend <0 && divisor >0) positive=false;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);

        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            sum += (1<<cnt);
            n=n-(d<<cnt);
        }
        if(sum >INT_MAX && positive) return INT_MAX;
        if(sum >INT_MAX && !positive) return INT_MIN;
        return positive ? sum : 0-sum;
        
    }
};