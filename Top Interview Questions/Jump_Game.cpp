// Approach-I: Same as Jumps Game-2. Time- O(N^2) + Space: O(N).

class Solution {
public:
    int INF=1e9+5;
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return true;
        }
        int jumps[n];
        for(int i=0;i<n;i++){
            jumps[i]=INF;
        }
        jumps[0]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i){
                    jumps[i]=min(jumps[i],1+jumps[j]);
                }
            }
        }
        if(jumps[n-1]!=INF){
            return true;
        }
        return false;
    }
};


// Approach:2 Time: O(N) + Space: O(1).

class Solution {
public:
     bool canJump(vector<int>& nums) {
        // Greedy- O(n)time and O(1) space.
        int LastGoodIndex=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i] >= LastGoodIndex){
                LastGoodIndex=i;
            }
        }
        if(LastGoodIndex==0){
            return true;
        }
        return false;
     }
};