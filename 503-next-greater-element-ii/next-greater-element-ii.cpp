class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            int currEle=nums[ind];
            while(!st.empty() && st.top()<=currEle){
                st.pop();
            }
            if(i<n){
                nge[i]=st.empty() ?  -1:st.top();
            }
            st.push(currEle);
        }
        return nge;
    }
};