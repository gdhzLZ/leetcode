class Solution {
public:
    bool isVaild(vector<vector<char>>& board,int posx,int posy){
        for(int i = 0 ; i < 9 ; i++){
            if(i == posx)
                continue;
            if(board[i][posy] == board[posx][posy])
                return false;
        }
        for(int i = 0 ; i < 9 ; i++){
            if(i == posy)
                continue;
            if(board[posx][i] == board[posx][posy])
                return false;
        }
        int x = posx - posx%3;
        int y = posy - posy%3;
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++){
                if((x+i) == posx && (y+j) == posy)
                    continue;
                if(board[x+i][y+j] == board[posx][posy])
                    return false;
            }
        
        return true;
    }
    bool dfs(vector<vector<char>>& board,stack<pair<int,int>> &Insert){
        if(Insert.size() == 0)
            return true;
        pair<int,int> now = Insert.top();
        Insert.pop();
        for(int i = 1 ;  i <= 9 ; i++){
            char c = '0'+i;
            board[now.first][now.second] = c;
            if(isVaild(board,now.first,now.second) && dfs(board,Insert)){
                return true;
            }
        }
        board[now.first][now.second] = '.';
        Insert.push(now);
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        stack<pair<int,int>> Insert;
        for(int i = 0 ; i < board.size() ; i++)
            for(int j = 0 ; j < board[0].size(); j++)
                if(board[i][j] == '.')
                    Insert.push(make_pair(i,j));
        if(Insert.size() != 0){
            dfs(board,Insert);
        }
    }
};