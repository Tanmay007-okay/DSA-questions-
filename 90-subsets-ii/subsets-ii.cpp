class Solution {
public:
    void find(int ind,vector<int>& nums,vector<int>& ds,set<vector<int>>& result){ //using seet to tackle duplicates
        if(ind==nums.size()){
            result.insert(ds); // no push_back in set we use insert
            return;
        }
        ds.push_back(nums[ind]);
        // to pick the current
        find(ind+1,nums,ds,result);
        // not pick
        ds.pop_back();
        find(ind+1,nums,ds,result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(),nums.end());

        find(0,nums,ds,result);

        vector<vector<int>> ans(result.begin(), result.end());
        return ans;



        
    }
};