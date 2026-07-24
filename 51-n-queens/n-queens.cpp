class Solution {
public:
    bool Safe(int row, int col, vector<vector<char>> &board, int n) {
        // Check all columns to the left in the same row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }

        //  upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true; //if no attack
    }
    void solve(int col, vector<vector<char>> &board,
               vector<vector<string>> &ans, int n) {
        if (col == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                // Convert row vector to string
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        // Try placing queen in all rows of current column
        for (int row = 0; row < n; row++) {
            // Place queen only if safe
            if (Safe(row, col, board, n)) {
                // Place queen
                board[row][col] = 'Q';
                // Recurse for next column
                solve(col + 1, board, ans, n); 
                // Backtrack and remove queen
                board[row][col] = '.';        
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<vector<char>> board(n, vector<char>(n, '.'));

        solve(0, board, ans, n);
        return ans;
        
    }
};