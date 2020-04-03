#include <iostream>
#include <vector>

using namespace std;

class PhoneDirectory {
    vector<int> next;
    int maxNumbers;
    int pos;
public:
    PhoneDirectory(int maxNumbers) : maxNumbers(maxNumbers) {
        next.push_back(1);
        pos = 0;
    }

    int get() {
        if (pos == next.size()) {
            next.push_back(pos+1);
        }
        if (next.size() > maxNumbers) {
            next.pop_back();
            return -1;
        }
        int res = pos;
        pos = next[pos];
        next[res] = -1;
        return res;
    }

    bool check(int number) {
        return number < maxNumbers && (number >= next.size() || next[number] != -1);
    }

    void release(int number) {
        if (number < next.size() && next[number] == -1) {
            next[number] = pos;
            pos = number;
        }
    }
};