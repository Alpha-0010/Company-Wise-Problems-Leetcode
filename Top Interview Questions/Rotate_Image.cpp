class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if(rows==0){
            return;
        }
        int cols=matrix[0].size();
        // Transpose of the matrix.
        for(int i=0;i<rows;i++){
            for(int j=i+1;j<cols;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // Horizontal revrsal of the matrix.
        for(int i=0;i<rows;i++){
            int left=0,right=cols-1;
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};