class Solution {
public:
    void findCombination(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target){
            // add the current element to the combination 
            ds.push_back(arr[ind]);
            // continue with the same index
            findCombination(ind,target-arr[ind],arr,ans,ds);
            // backtracking
            ds.pop_back();
        }
        // skip the current element and move to the next index
        findCombination(ind+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  // To store the result
        vector<int> ds;  // To store a current combination
        findCombination(0, target, candidates, ans, ds);  // Start the recursive search
        return ans;  // Return all valid combinations
        
    }
};