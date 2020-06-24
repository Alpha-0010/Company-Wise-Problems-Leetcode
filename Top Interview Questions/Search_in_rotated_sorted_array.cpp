class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        if(n==1 and nums[0]==target){
            return 0;
        }
        if(n==1 and nums[0]!=target){
            return -1;
        }
        // Find the pivot point.
        int pivot;
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left)+(right-left)/2;
            if(mid==0){
                left=mid+1;
                continue;
            }
            if(nums[mid-1]>nums[mid]){
                pivot=mid;
                break;
            }else if(nums[mid]>=nums[left] and nums[mid]>nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        // Now we have the pivot of the nums array.
        // Now find in which range does the target lie .i.e. pivot to n-1
        // or 0 to pivot-1.
        left=pivot,right=n-1;
        if(nums[left]<=target and target<=nums[right]){
            left=pivot;
            right=n-1;
        }else{
            right=left-1;
            left=0;
        }
        // Now apply normal binary search to get the target.
        while(left<=right){
            int mid=(left)+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return -1;
    }
};