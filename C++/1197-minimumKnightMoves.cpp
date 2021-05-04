class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        set<pair<int, int>> visited;
        vector<vector<int>> dict = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {-1,2}, {1,2}, {1,-2}, {-1,-2}};
        visited.insert({0, 0});
        x = abs(x), y = abs(y);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int xVal = cur.first.first;
            int yVal = cur.first.second;
            int dist = cur.second;
            if (x == xVal && y == yVal) return dist;
            if (xVal < -2 || yVal < -2) continue;
            if (xVal > x + 2 || yVal > y + 2) continue;
            for (int k = 0; k < dict.size(); k++) {
                int newX = xVal + dict[k][0];
                int newY = yVal + dict[k][1];
                if (visited.find({newX, newY}) == visited.end()) {
                    visited.insert({newX, newY});
                    q.push({{newX, newY}, dist + 1});
                }
            } 
        }
        return 0;
    }
};