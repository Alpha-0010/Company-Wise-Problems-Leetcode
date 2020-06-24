// Iterative Approach.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int dp[n+1][m+1];
        // Base Cases.
        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=j;
        }
        // Fill up the dp matrix.
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};


// Recursive Approach.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n==0 or m==0){
            return max(n,m);
        }
        int** dp=new int*[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=new int[m+1];
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                dp[i][j]=-1;
            }
        }
        return min_operations(word1,word2,n,m,dp);
    }
    int min_operations(string word1,string word2,int n,int m,int** dp){
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(word1[n-1]==word2[m-1]){
            dp[n][m]=min_operations(word1,word2,n-1,m-1,dp);
            return dp[n][m];
        }
        // Replace a char.
        int ans1=1+min_operations(word1,word2,n-1,m-1,dp);
        // Insert.
        int ans2=1+min_operations(word1,word2,n,m-1,dp);
        // Delete.
        int ans3=1+min_operations(word1,word2,n-1,m,dp);
        dp[n][m]=min(ans1,min(ans2,ans3));
        return dp[n][m];
    }
};