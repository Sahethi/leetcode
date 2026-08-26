class TicTacToe {
    vector<vector<int>> board;
    /**
      0 1 2
    0
    1
    2
    **/
public:
    TicTacToe(int n) {
        board.resize(n, vector<int>(n,0));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;

        if (board[0][0] != 0 &&
            board[0][0] == board[0][1] &&
            board[0][1] == board[0][2])
            return board[0][0];

        // Row 1
        if (board[1][0] != 0 &&
            board[1][0] == board[1][1] &&
            board[1][1] == board[1][2])
            return board[1][0];

        // Row 2
        if (board[2][0] != 0 &&
            board[2][0] == board[2][1] &&
            board[2][1] == board[2][2])
            return board[2][0];

        // Column 0
        if (board[0][0] != 0 &&
            board[0][0] == board[1][0] &&
            board[1][0] == board[2][0])
            return board[0][0];

        // Column 1
        if (board[0][1] != 0 &&
            board[0][1] == board[1][1] &&
            board[1][1] == board[2][1])
            return board[0][1];

        // Column 2
        if (board[0][2] != 0 &&
            board[0][2] == board[1][2] &&
            board[1][2] == board[2][2])
            return board[0][2];

        // Main diagonal
        if (board[0][0] != 0 &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return board[0][0];

        // Anti-diagonal
        if (board[0][2] != 0 &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return board[0][2];

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */