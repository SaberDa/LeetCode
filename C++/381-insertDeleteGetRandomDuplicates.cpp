#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, int> nums;
    vector<int> cans;
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        bool res = true;
        if (find(cans.begin(), cans.end(), val) != cans.end()) {
            res = false;
        }
        cans.push_back(val);
        nums[cans.size() - 1] = val;
        return res;
    }

    bool remove(int val) {
        if (find(cans.begin(), cans.end(), val) == cans.end()) {
            return false;
        }
        int last = cans.back();
        int valPos = find(cans.begin(), cans.end(), val) - cans.begin();
        int lastPos = cans.size() - 1;
        nums[valPos] = last;
        nums.erase(lastPos);
        cans[valPos] = last;
        cans.pop_back();
        return true;
    }

    int getRandom() {
        return cans[rand() % cans.size()];
    }

};