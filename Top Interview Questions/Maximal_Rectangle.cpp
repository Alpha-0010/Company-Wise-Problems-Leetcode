// This problem can be done using the concept of Histogram with maximum area.

// Here we are calculating area for a given bar 'i'. Area= Height of the smallest bar to the left* width.
// Width= index of the right bar(i-1) - width of the left bar(s.top()).

// If matrix[i][j]==1 then make matrix[i][j]=matrix[i-1][j]+matrix[i][j].
// And calculate max_area for each of the matrix.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        if(rows==0){
            return 0;
        }
        int cols=matrix[0].size();
        int max_area=hist(matrix[0]);
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    int val=(matrix[i][j]-'0')+(matrix[i-1][j]-'0');
                    matrix[i][j]=(val+'0');
                }
            }
            max_area=max(max_area,hist(matrix[i]));
        }
        return max_area;
    }
    int hist(vector<char>heights){
        int n=heights.size();
        if(n==0){
            return 0;
        }
        stack<int>s;
        int i=0;
        int max_area=0;
        while(i<n){
            if(s.size()==0 or (heights[s.top()]-'0')<=(heights[i]-'0')){
                s.push(i);
                i++;
            }else{
                int tp=s.top();
                s.pop();
                int area=(heights[tp]-'0')*(s.size()==0 ? i : i-1-s.top());
                max_area=max(max_area,area);
            }
        }
        while(s.size()!=0){
            int tp=s.top();
            s.pop();
            int area=(heights[tp]-'0')*(s.size()==0 ? i : i-1-s.top());
            max_area=max(max_area,area);
        }
        return max_area;
    }
};