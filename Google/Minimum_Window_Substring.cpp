class Solution {
public:
    string minWindow(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        int hash_pat[256]={0};
        int hash_str[256]={0};
        int start=0,start_index=-1;
        int min_len=INT_MAX;
        int count=0;
        for(int i=0;i<len2;i++){
            hash_pat[t[i]]++;
        }
        for(int i=0;i<len1;i++){
            hash_str[s[i]]++;
            
            // We will grow until the frequency of s[i] are not same in str and pat or str[i] is present in pat.
            if(hash_str[s[i]]<=hash_pat[s[i]] and hash_pat[s[i]]!=0){
                count+=1;
            }
            
            // Now if all the characters of pat are present in str we will shrink.
            if(count==len2){
                while(hash_str[s[start]]>hash_pat[s[start]] or hash_pat[s[start]]==0 ){
                    hash_str[s[start]]-=1;
                    start+=1;
                }
                int window_len=i-start+1;
                if(min_len>window_len){
                    min_len=window_len;
                    start_index=start;
                }
            }
            
        }
        if(start_index==-1){
            return "";
        }else{
            return s.substr(start_index,min_len);
        }
    }
};
