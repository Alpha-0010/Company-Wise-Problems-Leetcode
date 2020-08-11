class Solution {
public:
    // So basically in this problem:
    // (i) First push all the intervals which should come before newInterval.
    // (ii) Then push all the intersecting intervals with the newInterval.
    // (iii) Finally push all the intervals that should come after newInterval.
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        if(newInterval.size()==0){
            return intervals;
        }
        int idx=0;
        // Step1.
        while(idx<n and intervals[idx][1]<newInterval[0]){
            res.push_back(intervals[idx++]);
        }
        // Step2.
        while(idx<n and intervals[idx][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[idx][0]);
            newInterval[1]=max(newInterval[1],intervals[idx][1]);
            idx++;
        }
        res.push_back(newInterval);
        // Step3.
        while(idx<n){
            res.push_back(intervals[idx++]);
        }
        return res;
    }
};