// Refer:
// https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time


// Put each number at its right place .i.e. number 5 should go to nums[4]. Finally run a for loop and find
// the index 'i' where nums[i]!=i+1 return i+1. If we couldn't find any such 'i' then return 'n+1'.


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 1;
        }
        for(int i=0;i<n;i++){
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
