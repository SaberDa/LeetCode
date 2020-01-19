#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    int k = -1  ;

    if (nums.empty()) {
        return 0;
    }

    unordered_map<int, int> m;
    int ans = 0;
    int sum = 0;
    for (int i =0; i < nums.size(); i++) {
        sum += nums[i];
        if (!m.count(sum)) {
            m[sum] = i;
        }
        // m[sum] = i;
        if (sum == k) {
            ans = max(ans, i+1);
        }
        if (m.count(sum-k)) {
            int length = i - m[sum-k];
            ans = max(ans, length);
        }
    }

    cout << ans <<endl;

    return 0;
}