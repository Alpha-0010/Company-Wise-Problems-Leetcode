// Formula: min(left_max,right_max)-height[i].

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=1){
            return 0;
        }
        vector<int>left(n,0);
        vector<int>right(n,0);
        int left_max=height[0];
        int right_max=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=left_max;
            left_max=max(left_max,height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right_max;
            right_max=max(right_max,height[i]);
        }
        int total=0;
        for(int i=1;i<n-1;i++){
            int water=min(left[i],right[i])-height[i];
            if(water>0){
                total+=water;
            }
        }
        return total;
    }
};