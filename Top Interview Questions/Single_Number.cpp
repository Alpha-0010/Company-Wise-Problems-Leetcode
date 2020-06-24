
// Take XOR of all the numbers. XOR of 2 same numbers is 0 and XOR of 0 and a number is the number.
// So the XOR of all the numbers will cancel out duplicate elements and we will be left with the 
// number which occurs once in the array.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};