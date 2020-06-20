class Solution {
public:
    // Formula: min(left_max,right_max)-height[i].
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0){
            return 0;
        }
        int left[n];
        int right[n];
        int left_max,right_max;
        left_max=height[0];
        right_max=height[n-1];
        left[0]=0;
        right[n-1]=0;
        for(int i=1;i<n;i++){
            left[i]=left_max;
            left_max=max(left_max,height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right_max;
            right_max=max(right_max,height[i]);
        }
        int total_water=0;
        for(int i=1;i<n-1;i++){
            int x=min(left[i],right[i])-height[i];
            if(x>0){
                total_water+=x;
            }
        }
        return total_water;
    }
};