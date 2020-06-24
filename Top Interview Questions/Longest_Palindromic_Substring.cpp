class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0){
            return "";
        }
        int max_len=0;
        int start=0;
        // Odd Length Palindrome.
        for(int mid=0;mid<n;mid++){
            int left=mid,right=mid;
            int len=0;
            while(left>=0 and right<n and s[left]==s[right]){
                len=right-left+1;
                if(len>max_len){
                    max_len=len;
                    start=left;
                }
                left--;
                right++;
            }
        }
        // Even Length Palindrome.
        for(int mid=0;mid<n-1;mid++){
            int left=mid,right=mid+1;
            int len=0;
            while(left>=0 and right<n and s[left]==s[right]){
                len=right-left+1;
                if(len>max_len){
                    max_len=len;
                    start=left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,max_len);
    }
};