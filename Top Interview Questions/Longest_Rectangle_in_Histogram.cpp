// Refer this:
// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

// Here we are calculating area for a given bar 'i'. Area= Height of the smallest bar to the left* width.
// Width= index of the right bar(i-1) - width of the left bar(s.top()).

class Solution {
public:
    stack<int>s;
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0){
            return 0;
        }
        int i=0;
        int max_area=0;
        while(i<n){
            if(s.size()==0 or heights[s.top()]<=heights[i]){
                s.push(i);
                i++;
            }else{
                int tp=s.top();
                s.pop();
                int area=heights[tp]*(s.size()==0 ? i : i-1-s.top());
                max_area=max(max_area,area);
            }
        }
        while(s.size()!=0){
            int tp=s.top();
            s.pop();
            int area=heights[tp]*(s.size()==0 ? i : i-1-s.top());
            max_area=max(max_area,area);
        }
        return max_area;
    }
};