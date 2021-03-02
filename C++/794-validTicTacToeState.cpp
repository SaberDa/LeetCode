class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool x = false, y = false;
        int xC = 0, yC = 0;
        vector<vector<int>> dict(3, vector<int>(3, -1));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[i][j];
                if (c == 'X') {
                    xC++;
                    dict[i][j] = 1;
                } else if (c == 'O') {
                    yC++;
                    dict[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (dict[i][0] == dict[i][1] && dict[i][0] == dict[i][2]) {
                if (dict[i][0] == 1) x = true;
                else if (dict[i][0] == 0) y = true;
            }
            if (dict[0][i] == dict[1][i] && dict[0][i] == dict[2][i]) {
                if (dict[0][i] == 1) x = true;
                else if (dict[0][i] == 0) y = true;
            }
        }
        if (dict[0][0] == dict[1][1] && dict[0][0] == dict[2][2]) {
            if (dict[0][0] == 1) x = true;
            else if (dict[0][0] == 0) y = true;
        }
        if (dict[0][2] == dict[1][1] && dict[0][2] == dict[2][0]) {
            if (dict[0][2] == 1) x = true;
            else if (dict[0][2] == 0) y = true;
        }
        
        if (x && y) return false;
        if (x && xC - 1 != yC) return false;
        if (y && xC != yC) return false;
        if (xC - yC > 1 || xC - yC < 0) return false;
        return true;
    }
};