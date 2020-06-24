class Solution {
public:
    // 2-Pointer approach.
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n<=1){
            return 0;
        }
        int left=0,right=n-1;
        int max_area=0;
        while(left<right){
            if(height[left]<height[right]){
                int area=(right-left)*height[left];
                max_area=max(max_area,area);
                left++;
            }else{
                int area=(right-left)*height[right];
                max_area=max(max_area,area);
                right--;
            }
        }
        return max_area;
    }
};