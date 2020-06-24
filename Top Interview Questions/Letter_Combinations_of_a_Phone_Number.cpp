class Solution {
public:
    string mappings[10]={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0){
            return {};
        }
        vector<string>output;
        int idx=0;
        LetterHelper(digits,idx,"",output);
        return output;
    }
    void LetterHelper(string digits,int idx,string curr,vector<string>& output){
        if(idx==digits.size()){
            output.push_back(curr);
            return;
        }
        string str=mappings[digits[idx]-'0'];
        for(int i=0;i<str.length();i++){
            LetterHelper(digits,idx+1,curr+str[i],output);
        }
    }
};