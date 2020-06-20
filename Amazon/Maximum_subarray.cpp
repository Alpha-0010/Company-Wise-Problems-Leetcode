// Kadane's Algorithm.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(curr<0){
                curr=0;
            }
            if(curr>maxi){
                maxi=curr;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                count++;
            }
        }
        if(count==n){
            maxi=nums[0];
            for(int i=1;i<n;i++){
                if(nums[i]>maxi){
                    maxi=nums[i];
                }
            }
            return maxi;
        }else{
            return maxi;
        }
        
    }
};