class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1){
            return s;
        }
        int max_len=0,start_idx=0;
        // Odd length Substring.
        for(int mid=0;mid<n;mid++){
            int left=mid,right=mid;
            while(left>=0 and right<n and s[left]==s[right]){
                int len=right-left+1;
                if(len>max_len){
                    max_len=len;
                    start_idx=left;
                }
                left--;
                right++;
            }
        }
        // Even length Substring.
        for(int mid=0;mid<n-1;mid++){
            int left=mid,right=mid+1;
            while(left>=0 and right<n and s[left]==s[right]){
                int len=right-left+1;
                if(len>max_len){
                    max_len=len;
                    start_idx=left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start_idx,max_len);
    }
};