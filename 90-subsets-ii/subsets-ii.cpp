class Solution {
public:
    void find(int ind,vector<int>& nums,vector<int>& current,vector<vector<int>>& result){
        result.push_back(current);

        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i] == nums[i-1]) continue;

            current.push_back(nums[i]);
            
            find(i+1,nums,current,result);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(),nums.end());

        find(0,nums,current,result);

        
        return result;



        
    }
};