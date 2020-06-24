class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            if(i==0 or(i>0 and nums[i]!=nums[i-1]) ){
                int left=i+1,right=n-1;
                while(left<right){
                    int sum=nums[i]+nums[left]+nums[right];
                    if(sum==0){
                        res.push_back({nums[i],nums[left],nums[right]});
                        // Now to avoid duplicate elements.
                        while(left<right and nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left<right and nums[right]==nums[right-1]){
                            right--;
                        }
                        left++;
                        right--;
                    }else if(sum<0){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return res;
    }
};