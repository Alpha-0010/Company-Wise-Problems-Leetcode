// Can be done using 2 passes.
// 1st to store the last index of the each character.
// 2nd one to record the end of the current substring.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n=S.length();
        if(n==0){
            return {};
        }
        vector<int> output;
        int hash[256]={0};
        // Store the last index of each character in hash array.
        for(int i=0;i<n;i++){
            hash[S[i]]=i;
        }
        
        // Now record the end of the current substring.
        int start=0,last=0;
        for(int i=0;i<n;i++){
            last=max(last,hash[S[i]]);
            if(last==i){
                int len=last-start+1;
                output.push_back(len);
                start=i+1;
            }
        }
        return output;
    }
};