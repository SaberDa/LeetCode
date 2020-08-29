#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Robot {
public:
    bool move();
    void turnLeft();
    void turnRight();
    void clean();
};

string tostr(int r, int c) {
    return to_string(r) + "," + to_string(c);
}

void helper(Robot &R, int r, int c, unordered_set<string>& visited) {
    if (visited.count(tostr(r, c))) return;
    R.clean();
    visited.insert(tostr(r, c));

    // Robots always end with up

    // up
    if (R.move()) {
        helper(R, r - 1, c, visited);
        R.turnLeft();
        R.turnLeft();
        R.move();
        R.turnLeft();
        R.turnLeft();
    }

    // left
    R.turnLeft();
    if (R.move()) {
        R.turnRight();
        helper(R, r, c - 1, visited);
        R.turnRight();
        R.move();
        R.turnLeft();
        R.turnLeft();
    }
    R.turnRight();

    // right
    R.turnRight();
    if (R.move()) {
        R.turnLeft();
        helper(R, r, c + 1, visited);
        R.turnLeft();
        R.move();
        R.turnLeft();
        R.turnLeft();
    }
    R.turnLeft();

    // down
    R.turnLeft();
    R.turnLeft();
    if (R.move()) {
        R.turnLeft();
        R.turnLeft();
        helper(R, r + 1, c, visited);
        R.move();
        R.turnLeft();
        R.turnLeft();
    }
    R.turnLeft();
    R.turnLeft();
}

void cleanRoom(Robot &robot) {
    unordered_set<string> visited;
    helper(robot, 0, 0, visited);
}