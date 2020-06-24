// Approach-I: Using the concept of backtracking + using boolean array to mark if already visited.
// O(N) Time + O(N) Space.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        vector<vector<int>> res;
        bool* used=new bool[n];
        for(int i=0;i<n;i++){
            used[i]=false;
        }
        PermutationHelper(nums,res,{},used);
        return res;
    }
    void PermutationHelper(vector<int>& nums,vector<vector<int>>& res,vector<int> curr,bool* used){
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


// Approach-II: O(N) Time + O(1) Space.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> output;
        if(n==0){
            return output;
        }
        Helper(nums,output,0);
        return output;
    }
    void Helper(vector<int> nums,vector<vector<int>>& output,int index){
        if(index==nums.size()-1){
            output.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            Helper(nums,output,index+1);
            swap(nums[i],nums[index]);
        }
    }
};