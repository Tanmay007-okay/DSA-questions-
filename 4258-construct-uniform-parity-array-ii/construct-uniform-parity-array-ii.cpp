class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int m=INT_MAX;
        for(int x:nums1){
            if(x%2==1)m=min(m,x);
        }
        for(int x:nums1){
            if(x%2==0 && m!=INT_MAX && x<m)return false;
        }
        return true;
    }
};