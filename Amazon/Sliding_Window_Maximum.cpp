// We can use deque Data Structure in this problem. or we can use 2 array pass method.
// Link: https://leetcode.com/problems/sliding-window-maximum/discuss/65881/O(n)-solution-in-Java-with-two-simple-pass-in-the-array

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        int left_max[n],right_max[n];
        left_max[0]=nums[0];
        right_max[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            if(i%k==0){
                left_max[i]=nums[i];
            }else{
                left_max[i]=max(nums[i],left_max[i-1]);
            }
        }
        for(int j=n-2;j>=0;j--){
            if(j%k==0){
                right_max[j]=nums[j];
            }else{
                right_max[j]=max(nums[j],right_max[j+1]);
            }
        }
        
        vector<int>sliding_window_max(n-k+1,0);
        for(int i=0,j=0;i+k<=n;i++){
            sliding_window_max[j++]=max(right_max[i],left_max[i+k-1]);
        }
        return sliding_window_max;
    }
};

