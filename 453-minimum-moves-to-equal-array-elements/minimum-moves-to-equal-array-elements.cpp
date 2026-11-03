class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int mi = INT_MAX;
        // int ma = INT_MIN;
        // int sum=0;
        // for (int i = 0; i < nums.size(); i++) {
        //     mi= min(mi, nums[i]);
        //     sum+=nums[i];

        // }
        // return sum-nums.size()*mi;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        for(int i=n-1;i>0;i--){
            sum+=nums[i]-nums[0];
        }
        return sum;
    }
};