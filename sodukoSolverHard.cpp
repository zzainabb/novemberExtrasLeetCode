#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool usedRow[9][9], usedCol[9][9], usedBox[9][9];
    bool doSolveSudoku(vector<vector<char>>& board, int row) {
        for (int i = row; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; ++k) {
                        if (!usedRow[i][k - 1] && !usedCol[j][k - 1] &&
                            !usedBox[i / 3 * 3 + j / 3][k - 1])
                        {
                            board[i][j] = '0' + k;
                            usedRow[i][k - 1] = true;
                            usedCol[j][k - 1] = true;
                            usedBox[i / 3 * 3 + j / 3][k - 1] = true;
                            if (doSolveSudoku(board, i))
                                return true;
                            board[i][j] = '.';
                            usedRow[i][k - 1] = false;
                            usedCol[j][k - 1] = false;
                            usedBox[i / 3 * 3 + j / 3][k - 1] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                usedRow[i][j] = false;
                usedCol[i][j] = false;
                usedBox[i][j] = false;
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    int val = board[i][j] - '0';
                    usedRow[i][val - 1] = true;
                    usedCol[j][val - 1] = true;
                    usedBox[i / 3 * 3 + j / 3][val - 1] = true;
                }
            }
        }
        doSolveSudoku(board, 0);
    }
};