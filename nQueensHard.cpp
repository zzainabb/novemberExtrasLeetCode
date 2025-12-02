#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<bool> col, diag, anti;

    void backtrack(int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag[row + c] || anti[row - c + n - 1])
                continue;

            board[row][c] = 'Q';
            col[c] = diag[row + c] = anti[row - c + n - 1] = true;

            backtrack(row + 1, n);

            board[row][c] = '.';
            col[c] = diag[row + c] = anti[row - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();

        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        diag = vector<bool>(2 * n - 1, false);
        anti = vector<bool>(2 * n - 1, false);

        backtrack(0, n);
        return result;
    }
};
