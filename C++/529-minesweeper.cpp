class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        deque<pair<int, int>> q;
        q.push_back({click[0], click[1]});
        while (!q.empty()) {
            auto r = q.front().first, c = q.front().second;
            q.pop_front();
            int mines = 0;
            vector<pair<int, int>> nei;
            if (board[r][c] == 'M') board[r][c] = 'X';
            else for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (r + i >= 0 && c + j >= 0 && r + i < board.size() && c + j < board[0].size()) {
                        if (board[r + i][c + j] == 'M') mines++;
                        else if (mines == 0 && board[r + i][c + j] == 'E') nei.push_back({r + i, c + j});
                    }
                }
            }
            if (mines > 0) board[r][c] = '0' + mines;
            else for (auto it : nei) {
                board[it.first][it.second] = 'B';
                q.push_back(it);
            }
        }
        return board;
    }
};