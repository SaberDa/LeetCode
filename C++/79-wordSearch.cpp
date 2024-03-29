#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void backtrack(vector<vector<char>>& board, int pos, int r, int c, int m, int n, string& word, bool& res) {
    if (board[r][c] == '0' || res) {
        return;
    }
    if (pos == word.size()) {
        res = true;
        return;
    }
    char temp = board[r][c];
    board[r][c] = '0';
    if (r-1 >= 0 && board[r-1][c] == word[pos]) backtrack(board, pos+1, r-1, c, m, n, word, res);
    if (r+1 < m  && board[r+1][c] == word[pos]) backtrack(board, pos+1, r+1, c, m, n, word, res);
    if (c+1 < n  && board[r][c+1] == word[pos]) backtrack(board, pos+1, r, c+1, m, n, word, res);
    if (c-1 >= 0 && board[r][c-1] == word[pos]) backtrack(board, pos+1, r, c-1, m, n, word, res);
    board[r][c] = temp;
}

bool BFS(vector<vector<char>>& board, int r, int c, int m, int n, int len, string& word) {
    if (len == word.size()) {
        return true;
    }
    if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '0' || board[r][c] != word[len]) {
        return false;
    }
    char temp = board[r][c];
    board[r][c] = '0';
    bool found = BFS(board, r+1, c, m, n, len+1, word) ||
                 BFS(board, r-1, c, m, n, len+1, word) ||
                 BFS(board, r, c-1, m, n, len+1, word) ||
                 BFS(board, r, c+1, m, n, len+1, word);
    board[r][c] = temp;
    return found;
}

int main() {

    vector<vector<char>> board;
    board.push_back({ 'A','B','C','E' });
    board.push_back({ 'S','F','C','S' });
    board.push_back({ 'A','D','E','E' });

    string word;
    word = "ABCCED";

    bool res = false;
    int m = board.size();
    if (m == 0) {
        res = false;
        cout << res << endl;
    }
    int n = board[0].size();
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (board[i][j] == word[0]) {
    //             backtrack(board, 1, i, j, m, n, word, res);
    //         }
    //         if (res) {
    //             cout << res << endl;
    //         }
            
    //     }
    // }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0] && BFS(board, i, j, m, n, 0, word)) {
               res = true;
               cout << res << endl; 
               return 0;
            }
        }
    }

    cout << res << endl;

    return 0;
}