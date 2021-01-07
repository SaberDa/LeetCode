#include <vector>

using namespace std;

bool judge(vector<vector<int>> &board, int m, int n) {
    vector<vector<int>> copy(board);
    bool canCrushed = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            int r = i, c = j, count = 0;
            while (c < n && board[i][c] == board[i][j]) {
                ++c;
                ++count;
            }
            if (count >= 3) {
                canCrushed = true;
                while (c > j) copy[i][--c] = 0;
            }
            count = 0;
            while (r < m && board[r][j] == board[i][j]) {
                ++r;
                ++count;
            }
            if (count >= 3) {
                canCrushed = true;
                while (r > i) copy[--r][j] = 0;
            }
        }
    }
    board = copy;
    return canCrushed;
}

void drop(vector<vector<int>> &board, int m, int n) {
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                int r = i, c = j;
                while (r >= 0 && board[r][c] == 0) r--;
                if (r >= 0) swap(board[i][j], board[r][c]);
            }
        }
    }
}

vector<vector<int>> candyCrush(vector<vector<int>> &board) {
    if (board.empty()) return board;
    int m = board.size(), n = board[0].size();
    while (judge(board, m, n)) {
        drop(board, m, n);
    }
    return board;
}