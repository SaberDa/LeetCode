#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Logger {
private:
    unordered_map<string, int> mp;
public:
    /** Initialize your data structure here. */
    Logger() {
        mp.clear();
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.find(message) == mp.end() || timestamp - mp[message] >= 10) {
            mp[message] = timestamp;
            return true;
        }
        return false;
    }
};