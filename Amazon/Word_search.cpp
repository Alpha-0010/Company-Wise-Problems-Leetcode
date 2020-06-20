class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and dfs(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int index){
        // Base case when we traverse over the whole word and the last chararter matches with 
        // board element.
        if(index==word.length()){
            return true;
        }
        
        // When our indeices go out of the board matrix then return false.
        if(i>=board.size() || j>=board[i].size() || i<0 || j<0 || board[i][j]!=word[index]){
            return false;
        }
        // Now traverse over all the 4 directions from the cell we are currently in.
        // First store the cell into a temp char variable  and replace that cell with an '0'
        // char in order to ensure that the given cell is only used once.
        char temp=board[i][j];
        board[i][j]='0';
        bool found=dfs(board,i+1,j,word,index+1) || dfs(board,i,j+1,word,index+1) ||                    dfs(board,i-1,j,word,index+1) || dfs(board,i,j-1,word,index+1);
        board[i][j]=temp;
        return found;
    }
};