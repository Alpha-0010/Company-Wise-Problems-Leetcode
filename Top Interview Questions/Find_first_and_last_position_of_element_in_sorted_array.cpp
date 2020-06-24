class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        int first_occ=-1,last_occ=-1;
        int left=0,right=n-1;
        // First occ.
        while(left<=right){
            int mid=(left)+(right-left)/2;
            if(nums[mid]==target){
                first_occ=mid;
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        // Last occ.
        left=0,right=n-1;
        while(left<=right){
            int mid=(left)+(right-left)/2;
            if(nums[mid]==target){
                last_occ=mid;
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return {first_occ,last_occ};
    }
};