#include <isotream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    helper(res, n, k, vector<int>());
    return res;
}

void helper(vector<vector<int>>& res, int n, int k, vector<int> temp) {
    if (k == 0) {
        res.push_back(temp);
        return;
    }
    if (n > k) {
        helper(res, n - 1, k, temp);
    }
    temp.push_back(n);
    helper(res, n - 1, k - 1, temp);
}
