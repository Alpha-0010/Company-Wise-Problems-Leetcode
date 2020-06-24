class Solution {
public:
    // Sliding Window.
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0 or n==1){
            return n;
        }
        int start=0,max_len=1;
        int hash[256]={0};
        for(int i=0;i<n;i++){
            hash[s[i]]++;
            // Shrink window.
            while(hash[s[i]]>1){
                hash[s[start]]--;
                start++;
            }
            int len=i-start+1;
            max_len=max(max_len,len);
        }
        return max_len;
    }
};