class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return false;
        }
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(nums[mid]==target){
                return true;
            }
            // The main diff. between the search in rotated array with duplicate and 
            // Non-duplicate elements.
            if(nums[left]==nums[mid] and nums[mid]==nums[right]){
                left++;
                right--;
            }
            // The case if the part from left to mid part is sorted.
            else if(nums[left]<=nums[mid]){
                // If the target is in the part left to mid.
                if(nums[left]<=target and nums[mid]>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(nums[mid]<target and target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};