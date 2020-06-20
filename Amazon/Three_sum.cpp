class Solution {
public:
    // Sorting + 2-Pointer.
    // Take care of the duplicate arrays.
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> output;
        if(n==0){
            return output;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0 or(i>0 and nums[i]!=nums[i-1])){
                int left=i+1,right=n-1;
                while(left<right){
                    int sum=nums[i]+nums[left]+nums[right];
                    if(sum==0){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        output.push_back(v);
                        while(left<right and nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left<right and nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }else if(sum>0){
                        right--;
                    }else{
                        left++;
                    }
                }
            }
        }
        return output;
    }
};