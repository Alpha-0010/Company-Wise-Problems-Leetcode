// Application of Priority Queue.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n=points.size();
        if(n==0){
            return {};
        }
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(int i=0;i<n;i++){
            pq.push(points[i]);
            if(pq.size()>K){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(pq.size()!=0){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
    struct compare{
      bool operator()(const vector<int>& p1,const vector<int>& p2){
          return p1[0]*p1[0]+p1[1]*p1[1]<p2[0]*p2[0]+p2[1]*p2[1];
      }  
    };
};