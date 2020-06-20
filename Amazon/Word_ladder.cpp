class Solution {
public:
    // For explanation refer this:
    // https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        int ladder=1;
        while(q.size()!=0){
            int n=q.size();
            for(int i=0;i<n;i++){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return ladder;
                }
                for(int j=0;j<word.size();j++){
                    char c=word[j];
                    for(int k=0;k<26;k++){
                        word[j]='a'+k;
                        if(dict.find(word)!=dict.end()){
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[j]=c;
                }
            }
            ladder++;
        }
        return 0;
    }
};