#include <vector>

using namespace std;

int twoCitySchedCost(vector<vector<int>> &costs) {
    int res = 0;
    auto comp = [](vector<int> &a, vector<int> &b){ return a[0] - a[1] < b[0] - b[1]; };
    sort(costs.begin(), costs.end(), comp);
    for (int i = 0, j = costs.size() - 1; i < j; i++, j--) {
        res += costs[i].front() + costs[j].back(); 
    }
    return res;
}