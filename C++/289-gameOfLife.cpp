#include <iostream>
#include <vector>

using namespace std;

int cntNeighbor(vector<vector<int>>& board, int m, int n, int r, int c) {
    int cnt = 0;
    for (int i = max(0, r-1); i <= min(m, r+1); i++) {
        for (int j = max(0, c-1); j <= min(n, c+1); j++) {
            if ((i != r || j != c) && board[i][j] & 1) {
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {

    vector<vector<int>> board;
    board.push_back({ 0,1,0 });
    board.push_back({ 0,0,1 });
    board.push_back({ 1,1,1 });
    board.push_back({ 0,0,0 });

    if (board.empty()) {
        return 0;
    }

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int neighbor = cntNeighbor(board, m-1, n-1, i, j);
            if ((neighbor == 2 && board[i][j]) || (neighbor == 3)) {
                board[i][j] |= 2;
            }
        }
    }
    for (auto& i : board) {
        for (auto& j : i) {
            j >>= 1;
        }
    }

    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << " " << endl;
    }

    return 0;
}