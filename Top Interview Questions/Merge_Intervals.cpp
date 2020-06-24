class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0){
            return {};
        }
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int last_end=intervals[0][1];
        int last_start=intervals[0][0];
        for(int i=1;i<n;i++){
            if(last_end>=intervals[i][0]){
                last_end=max(last_end,intervals[i][1]);
                last_start=last_start;
            }else{
                res.push_back({last_start,last_end});
                last_end=intervals[i][1];
                last_start=intervals[i][0];
            }
        }
        res.push_back({last_start,last_end});
        return res;
    }
};