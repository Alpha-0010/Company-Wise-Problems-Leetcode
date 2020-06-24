// Catalan's Number.

class Solution {
public:
    int numTrees(int n) {
        if(n==0){
            return 1;
        }
        int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=-1;
        }
        return count(n,dp);
    }
    int count(int n,int* dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=count(i-1,dp)*(1)*count(n-i,dp);
        }
        dp[n]=ans;
        return ans;
    }
};