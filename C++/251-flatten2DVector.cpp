#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Vector2D {
private:

    queue<int> q;

    void load(queue<int>& q, int x) {
        q.push(x);
    }

public:

    Vector2D(vector<vector<int>>& v) {
        for (auto x : v) {
            for (auto y : x) {
                load(q, y);
            }
        }
    }

    int next() {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() {
        if (q.empty()) return false;
        else return true;
    }

};