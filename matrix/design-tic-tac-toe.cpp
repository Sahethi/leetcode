class TicTacToe {
    vector<vector<int>> board;
    int n;

public:
    TicTacToe(int n) {
        this->n = n;
        board.resize(n, vector<int>(n, 0));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;

        //check for diff row
        bool win = true;
        for(int i=0; i<n; i++){
            if(board[i][col] != player){
                win = false;
                break;
            }
        }
        if(win) return player;

        //check for diff cols
        win = true;
        for(int i=0; i<n; i++){
            if(board[row][i] != player){
                win = false;
                break;
            }
        }
        if(win) return player;

        //check for diagonal
        if(row == col){
            win = true;
            for(int i=0; i<n; i++){
                if(board[i][i] != player){
                    win = false;
                    break;
                }
            }
            if(win) return player;
        }

        //ahhh i see if row + col is equal to n-1 if its anti diagonal
        if(row + col == n-1){
            win = true;
            for(int i=0; i<n; i++){
                if(board[i][n-1-i] != player){
                    win = false;
                    break;
                }
            }
            if(win) return player;
        }

        return 0;
    }
};