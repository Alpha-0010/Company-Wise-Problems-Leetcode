class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if(rows==0){
            return {};
        }
        int cols=matrix[0].size();
        vector<int>res;
        int row_begin=0,col_begin=0;
        int row_end=rows-1,col_end=cols-1;
        while(row_begin<=row_end and col_begin<=col_end){
            // First Row.
            for(int i=col_begin;i<=col_end;i++){
                res.push_back(matrix[row_begin][i]);
            }
            row_begin++;
            // Last Col.
            for(int i=row_begin;i<=row_end;i++){
                res.push_back(matrix[i][col_end]);
            }
            col_end--;
            // Last Row.
            if(row_begin<=row_end){
                for(int i=col_end;i>=col_begin;i--){
                    res.push_back(matrix[row_end][i]);
                }
            }
            row_end--;
            // First Col.
            if(col_begin<=col_end){
                for(int i=row_end;i>=row_begin;i--){
                    res.push_back(matrix[i][col_begin]);
                }
            }
            col_begin++;
        }
        return res;
    }
};