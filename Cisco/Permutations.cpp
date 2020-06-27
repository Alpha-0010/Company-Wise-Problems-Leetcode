class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        vector<vector<int>> res;
        vector<bool>used(n,false);
        PermutationHelper(nums,res,{},used);
        return res;
    }
    void PermutationHelper(vector<int>& nums,vector<vector<int>>& res,vector<int> curr,vector<bool>& used){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==false){
                used[i]=true;
                curr.push_back(nums[i]);
                PermutationHelper(nums,res,curr,used);
                used[i]=false;
                curr.pop_back();
            }
        }
    }
};