#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

class Leaderboard {
private:
    unordered_map<int, int> players;
    map<int, int, greater<int>> scores;

public:
    Leaderboard() {
        players.clear();
        scores.clear();
    }

    void addScore(int playerId, int score) {
        if (players.count(playerId)) scores[players[playerId]]--;
        players[playerId] += score;
        scores[players[playerId]]++;
    }

    int top(int k) {
        int res = 0;
        for (auto x : scores) {
            if (k == 0) break;
            res += min(k, x.second) * x.first;
            k -= min(k, x.second);
        }
        return res;
    }

    void reset(int playerId) {
        scores[players[playerId]]--;
        players.erase(playerId);
    }
};