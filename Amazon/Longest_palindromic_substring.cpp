class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0 or n==1){
            return s;
        }
        int max_len=0;
        int max_idx=0;
        // Odd length substring.
        for(int mid=0;mid<n;mid++){
            int left=mid,right=mid;
            while(left>=0 and right<n){
                if(s[left]==s[right]){
                    int len=right-left+1;
                    if(len>max_len){
                        max_len=len;
                        max_idx=left;
                    }
                    left--;
                    right++;
                }else{
                    break;
                }
            }
        }
        
        // Even length substring.
        for(int mid=0;mid<n-1;mid++){
            int left=mid,right=mid+1;
            while(left>=0 and right<n){
                if(s[left]==s[right]){
                    int len=right-left+1;
                    if(len>max_len){
                        max_len=len;
                        max_idx=left;
                    }
                    left--;
                    right++;
                }else{
                    break;
                }
            }
        }
        return s.substr(max_idx,max_len);
    }
};