#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int m = gas.size();
    int n = cost.size();
    int carry = 0;
    pair<int, int> car(0, 0);
    for (int i = 1; i < m; i++) {
        carry += gas[i - 1] - cost[i - 1];
        if (carry < car.second) {
            car = {i, carry};
        }
    }
    carry += gas[m - 1] - cost[n - 1];
    return carry >= 0 ? car.first : -1;
}