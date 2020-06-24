// Kadane's Algorithm.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int curr=0,maxi=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0){
                curr=0;
            }
        }
        if(maxi!=0){
            return maxi;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                count++;
            }
        }
        if(count!=n){
            return 0;
        }
        maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
};