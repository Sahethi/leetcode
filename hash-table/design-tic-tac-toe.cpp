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

        // Check row
        bool win = true;
        for (int j = 0; j < n; j++) {
            if (board[row][j] != player) {
                win = false;
                break;
            }
        }
        if (win) return player;

        // Check column
        win = true;
        for (int i = 0; i < n; i++) {
            if (board[i][col] != player) {
                win = false;
                break;
            }
        }
        if (win) return player;

        // Check main diagonal
        if (row == col) {
            win = true;

            for (int i = 0; i < n; i++) {
                if (board[i][i] != player) {
                    win = false;
                    break;
                }
            }

            if (win) return player;
        }

        // Check anti-diagonal
        if (row + col == n - 1) {
            win = true;

            for (int i = 0; i < n; i++) {
                if (board[i][n - 1 - i] != player) {
                    win = false;
                    break;
                }
            }

            if (win) return player;
        }

        return 0;
    }
};