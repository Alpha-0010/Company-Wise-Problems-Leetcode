class Solution {
public:
    // Maximum product of three numbers: max. of product of 3 maximum numbers and product of 
    // 2 smallest numbers and the maxiumum number.
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 1;
        }
        int max_1=INT_MIN;
        int max_2=INT_MIN;
        int max_3=INT_MIN;
        int min_1=INT_MAX;
        int min_2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>max_1){
                int temp1=max_1;
                int temp2=max_2;
                max_1=nums[i];
                max_2=temp1;
                max_3=temp2;
            }else if(nums[i]>max_2){
                int temp=max_2;
                max_2=nums[i];
                max_3=temp;
            }else if(nums[i]>max_3){
                max_3=nums[i];
            }
        }
        // We have 3 maximum numbers in the array in var. max_1,max_2,max_3.
        // Now search for 2 minimum numbers in the array.
        for(int i=0;i<n;i++){
            if(nums[i]<min_1){
                int temp=min_1;
                min_1=nums[i];
                min_2=temp;
            }else if(nums[i]<min_2){
                min_2=nums[i];
            }
        }
        return max(max_1*max_2*max_3,max_1*min_1*min_2);
    }
};