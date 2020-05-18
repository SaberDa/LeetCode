#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

struct Log {
    int id;
    string status;
    int timestamp;
};

vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n, 0);
    stack<Log> st;
    for (string log : logs) {
        stringstream ss(log);
        string temp, temp2, temp3;
        getline(ss, temp, ':');
        getline(ss, temp2, ':');
        getline(ss, temp3, ':');

        Log item = {stoi(temp), temp2, stoi(temp3)};
        if (item.status == "start") {
            st.push(item);
        } else {
            assert(st.top().id == item.id);

            int sumTime = item.timestamp - st.top().timestamp + 1;
            res[item.id] += sumTime;
            st.pop();

            if (!st.empty()) {
                assert(st.top().status == "start");

                res[st.top().id] -= sumTime;
            }
        }
    }
    return res;
}