class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->first,it->second});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>output;
        while(pq.size()!=0){
            output.emplace_back(pq.top().first);
            pq.pop();
        }
        reverse(output.begin(),output.end());
        return output;
    }
    private:
        struct compare{
            bool operator()(const pair<string,int>& p1,const pair<string,int>& p2){
                if(p1.second==p2.second){
                    return p1.first<p2.first;
                }
                return p1.second>p2.second;
            }
        };
};