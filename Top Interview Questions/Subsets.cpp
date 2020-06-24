class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        vector<vector<int>> res;
        SubsetsHelper(nums,res,{},0);
        return res;
    }
    void SubsetsHelper(vector<int>& nums,vector<vector<int>>& res,vector<int> curr,int idx){
        res.push_back(curr);
        if(idx==nums.size()){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            SubsetsHelper(nums,res,curr,i+1);
            curr.pop_back();
        }
    }
};