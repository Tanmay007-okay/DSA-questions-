class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        for(int i=1,len=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                len++;
                cnt=max(cnt,len);
            }else{
                len=1;
            }
        }
        for(int i=1,len=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                len++;
                cnt=max(cnt,len);
            }else{
                len=1;
            }
        }
        return cnt;
        
    }
};