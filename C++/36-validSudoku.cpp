#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

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

    bool res = true;

    if (board.empty()) {
        return 0;
    }

    int n = board.size();
    int m = board[0].size();
    vector<unordered_map<char, int>> col(n);
    vector<unordered_map<char, int>> row(m);
    vector<vector<unordered_map<char, int>>> temp(n/3, vector<unordered_map<char, int>>(n/3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            }
            if (row[i][c]++ > 0 || col[j][c]++ > 0 || temp[i/3][j/3][c]++ > 0) {
                res = false;
            }
        }
    }

    cout << res << endl;


    return 0;
}