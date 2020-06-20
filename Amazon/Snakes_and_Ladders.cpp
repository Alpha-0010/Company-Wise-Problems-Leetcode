class Solution {
public:
    unordered_map<int,list<int>>mp;
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows=board.size();
        if(rows==0){
            return 0;
        }
        int cols=board[0].size();
        int n=rows*rows;
        int game[n+1];
        for(int i=0;i<n+1;i++){
            game[i]=0;
        }
        int idx=1;
        bool flag=true;
        // Build the Ludo board(game).
        for(int i=rows-1;i>=0;i--){
            if(flag==true){
                for(int j=0;j<cols;j++){
                    if(board[i][j]!=-1){
                        int a=idx;
                        int b=board[i][j];
                        game[a]=b-a;
                    }
                    idx++;
                }
                flag=false;
            }else{
                for(int j=cols-1;j>=0;j--){
                    if(board[i][j]!=-1){
                        int a=idx;
                        int b=board[i][j];
                        game[a]=b-a;
                    }
                    idx++;
                }
                flag=true;
            }
        }
        // Build the adjacency list.
        for(int i=1;i<=n;i++){
            for(int dice=1;dice<=6;dice++){
                int j=i+dice;
                if(j<=n){
                    j=j+game[j];
                    if(j<=n){
                        mp[i].push_back(j);
                    }
                }
            }
        }
        mp[n].push_back(n);
        int src=1,dest=n;
        queue<int>q;
        unordered_map<int,int>dist;
        // Mark the distance of every node to Infinity.
        for(auto Node_pair : mp){
            dist[Node_pair.first]=-1;
        }
        // Mark only the distance of source node to 0.
        dist[src]=0;
        q.push(src);
        while(q.size()!=0){
            int Node=q.front();
            q.pop();
            for(int elem : mp[Node]){
                if(dist[elem]==-1){
                    q.push(elem);
                    dist[elem]=dist[Node]+1;
                }
            }
        }
        return dist[dest];
    }
};