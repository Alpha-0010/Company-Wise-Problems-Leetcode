class Solution {
public:
    int reverse(int x) {
        string str="";
        str+=to_string(x);
        if(x<0){
            str+="-";
        }
        
        int n=str.length();
        int i=0,j=n-1;
        while(i<=j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
               
        try{
            return stoi(str);
        }catch(...){
            return 0;
        }
    }
};