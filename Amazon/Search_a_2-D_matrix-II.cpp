class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0){
            return false;
        }
        int m=matrix[0].size();
        if(m==0){
            return false;
        }
        int sx=0;
        int sy=m-1;
        while(sx>=0 and sy>=0 and sx<n and sy<m){
            if(target==matrix[sx][sy]){
                return true;
            }else if(target>matrix[sx][sy]){
                sx++;
            }else{
                sy--;
            }
        }
        return false;
    }
};