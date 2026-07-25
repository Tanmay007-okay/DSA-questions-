class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == c)
                return false;
        }
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // If character found in sub-box, not valid
                if (board[boxRowStart + i][boxColStart + j] == c)
                    return false;
            }
            
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // If current cell is empty
                if (board[i][j] == '.') {
                    // Try all possible digits
                    for (char c = '1'; c <= '9'; c++) {
                        // Check if placing c is valid here
                        if (isValid(board, i, j, c)) {
                            // Place c tentatively
                            board[i][j] = c;

                            // Recur to solve rest of the board
                            if (solveSudoku(board))
                                return true; // If successful, return true

                            // If not successful, backtrack
                            board[i][j] = '.';
                        }
                    }
                    // If no digit can be placed here, return false to backtrack
                    return false;
                }
            }
        }
        // If all cells are filled correctly, return true
        return true;
    }
};