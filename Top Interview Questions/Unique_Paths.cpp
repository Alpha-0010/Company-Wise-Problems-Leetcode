class Solution {
public:
    int paths(int sx,int sy,int ex,int ey,int** dp){
        if(sx==ex and sy==ey){
            return 1;
        }
        if(sx>ex or sy>ey){
            return 0;
        }
        if(dp[sx][sy]!=-1){
            return dp[sx][sy];
        }
        int ans1=paths(sx+1,sy,ex,ey,dp);
        int ans2=paths(sx,sy+1,ex,ey,dp);
        dp[sx][sy]=ans1+ans2;
        return dp[sx][sy];
    }
    int bottom_up(int m,int n){
        long dp[m][n];
        // Base cases.
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        dp[0][0]=1;
        // Fill the dp matrix.
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        if(m==0 and n==0){
            return 1;
        }
        int** dp=new int*[m+1];
        for(int i=0;i<m+1;i++){
            dp[i]=new int[n+1];
        }
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                dp[i][j]=-1;
            }
        }
        return bottom_up(m,n);
        return paths(0,0,m-1,n-1,dp);
    }
};