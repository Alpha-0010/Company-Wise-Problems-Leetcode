class Solution {
public:
    // Maintain 3 counters for color 0,1 and 2.
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==0 or n==1){
            return;
        }
        int count0=0,count1=0,count2=n-1;
        while(count0<count2 and count1<=count2){
            if(nums[count1]==0){
                swap(nums[count0],nums[count1]);
                count0++;
                count1++;
            }else if(nums[count1]==1){
                count1++;
            }else{
                swap(nums[count1],nums[count2]);
                count2--;
            }
        }
    }
};