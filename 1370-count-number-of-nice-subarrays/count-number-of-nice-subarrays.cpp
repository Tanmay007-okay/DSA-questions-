class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        int l=0,r=0,res=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]%2 !=0){
                k--;
            }
            while(k<0){
                if(nums[l]%2 !=0) k++;
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;   
    }
    int numberOfSubarrays(vector<int>& nums,int k){
        return countAtMost(nums,k)-countAtMost(nums,k-1);
    }
};