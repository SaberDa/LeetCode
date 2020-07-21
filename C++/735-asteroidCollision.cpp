#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;
    for (auto x : asteroids) {
        if (res.empty() || res.back() < 0 || x > 0) res.push_back(x);
        else {
            while (!res.empty() && res.back() > 0 && abs(x) > res.back()) res.pop_back();
            if (res.empty() || res.back() < 0) res.push_back(x);
            else if (abs(x) == res.back()) res.pop_back();
        }
    }
    return res;
}