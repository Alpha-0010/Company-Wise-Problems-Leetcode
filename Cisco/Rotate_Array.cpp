class Solution {
public:
    // Reverse the first n-k elements, reverse the last k elements then reverse the whole array.
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return;
        }
        k=k%n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};