class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n==0){
            return {{}};
        }
        vector<vector<string>> output;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            output.push_back(it->second);
        }
        return output;
    }
};