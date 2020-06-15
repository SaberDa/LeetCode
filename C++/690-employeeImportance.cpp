#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
    if (employees.empty()) return 0;
    unordered_map<int, Employee*> mp;
    for (auto x : employees) mp[x->id] = x;
    int sum = 0;
    deque<Employee*> q;
    q.push_back(mp[id]);
    while (!q.empty()) {
        auto temp = q.front();
        q.pop_front();
        for (auto x : temp->subordinates) q.push_back(mp[x]);
        sum += temp->importance;
    }
    return sum;
}