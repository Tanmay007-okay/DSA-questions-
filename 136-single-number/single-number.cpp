class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int singleNum = 0;
for (int num : arr) {
    singleNum ^= num;
}
return singleNum;
        
    }
};