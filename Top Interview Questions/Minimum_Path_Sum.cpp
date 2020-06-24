// Recursive Approach.
class Solution {
public:
    int minpath(vector<vector<int>> grid,int sx,int sy,int ex,int ey,int** dp){
        if(sx==ex and sy==ey){
            return grid[ex][ey];
        } 
        if(sx>ex or sy>ey){
            return INT_MAX;
        }
        if(dp[sx][sy]!=-1){
            return dp[sx][sy];
        }
        int option1=minpath(grid,sx+1,sy,ex,ey,dp);
        int option2=minpath(grid,sx,sy+1,ex,ey,dp);
        dp[sx][sy]=grid[sx][sy]+min(option1,option2);
        return dp[sx][sy];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int sx=0,sy=0;
        int n=grid.size();
        int m=grid[0].size();
        int ex=grid.size()-1,ey=grid[0].size()-1;
        int** dp=new int*[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=new int[m+1];
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                dp[i][j]=-1;
            }
        }
        int ans=minpath(grid,sx,sy,ex,ey,dp);
        return ans;
       
    }
};

// Iterative Approach.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        if(rows==0){
            return 0;
        }
        int cols=grid[0].size();
        // Base Cases.
        int dp[rows][cols];
        dp[0][0]=grid[0][0];
        for(int i=1;i<rows;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<cols;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};