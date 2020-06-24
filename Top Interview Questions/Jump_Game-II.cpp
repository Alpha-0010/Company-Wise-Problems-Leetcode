// Build a jumps array of size n. jumps[i] denotes the minimum number of jumps required to reach i from the 
// 0th index. Time- O(N^2)+ Space- O(N).

class Solution {
public:
    int INF=1e9+5;
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int jumps[n];
        jumps[0]=0;
        for(int i=1;i<n;i++){
            jumps[i]=INF;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i){
                    jumps[i]=min(jumps[i],jumps[j]+1);
                }
            }
        }
        return jumps[n-1];
    }
};