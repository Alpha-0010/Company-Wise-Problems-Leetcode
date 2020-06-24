// Classic BackTracking Problem.
// Include candidates[i] in the solution only if sum+candidates[i] doesnot exceed target.
// After including it in the solution set remove it from the set to check for other possibilities.

class Solution {
public:
    void CombinationHelper(vector<int>& candidates,int target,int sum,vector<vector<int>>& res,int idx,vector<int> curr){
        if(target==sum){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(sum+candidates[i]<=target){
                curr.push_back(candidates[i]);
                CombinationHelper(candidates,target,sum+candidates[i],res,i,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        if(n==0){
            return {};
        }
        vector<vector<int>> res;
        CombinationHelper(candidates,target,0,res,0,{});
        return res;
    }
};