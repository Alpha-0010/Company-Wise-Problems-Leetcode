// Explained properly in Algo expert. No need to go for Algo Expert the code itself is self-explantory.

class Solution {
public:
    int INF=(int)1e9+5;
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int max_len=-INF;
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=false;
        }
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==false){
                mp[nums[i]]=true;
                int curr_len=1;
                // Go backwards from arr[i].
                int elem1=nums[i]-1;
                while(mp.find(elem1)!=mp.end()){
                    mp[elem1]=true;
                    curr_len++;
                    elem1=elem1-1;
                }
                // Now go in the forward direction from arr[i].
                int elem2=nums[i]+1;
                while(mp.find(elem2)!=mp.end()){
                    mp[elem2]=true;
                    curr_len++;
                    elem2=elem2+1;
                }
                max_len=max(max_len,curr_len);
            }
        }
        return max_len;
    }
};