#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> nextDot(vector<vector<char>>& board) {
    vector<int> finish(2, -1);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                finish[0] = i;
                finish[1] = j;
            }
        }
    }
    return finish;
}

bool isValid(vector<vector<char>>& board, int num, int row, int col) {
    for (int i = 0; i < board[0].size(); i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    int r = (row/3) * 3;
    int c = (col/3) * 3;
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    vector<int> newDot = nextDot(board);
    if (newDot[0] == -1 && newDot[1] == -1) {
        return true;
    }
    int row = newDot[0];
    int col = newDot[1];
    char c;
    for (int num = 1; num < 10; num++) {
        
        if (num == 1) {
            c = '1';
        } else if (num == 2) {
            c = '2';
        } else if (num == 3) {
            c = '3';
        } else if (num == 4) {
            c = '4';
        } else if (num == 5) {
            c = '5';
        } else if (num == 6) {
            c = '6';
        } else if (num == 7) {
            c = '7';
        } else if (num == 8) {
            c = '8';
        } else {
            c = '9';
        }

        if (isValid(board, c, row, col)) {
            board[row][col] = c;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {

    vector<vector<char>> board;
    board.push_back({ '5','3','.','.','7','.','.','.','.' });
    board.push_back({ '6','.','.','1','9','5','.','.','.' });
    board.push_back({ '.','9','8','.','.','.','.','6','.' });
    board.push_back({ '8','.','.','.','6','.','.','.','3' });
    board.push_back({ '4','.','.','8','.','3','.','.','1' });
    board.push_back({ '7','.','.','.','2','.','.','.','6' });
    board.push_back({ '.','6','.','.','.','.','2','8','.' });
    board.push_back({ '.','.','.','4','1','9','.','.','5' });
    board.push_back({ '.','.','.','.','8','.','.','7','9' });


    solveSudoku(board);

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << " " << endl;
    }

    return 0;
}