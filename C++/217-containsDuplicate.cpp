#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    if (nums.empty()) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    bool res = false;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] == nums[i]) {
            res = true;
        }
    }

    cout << res << endl;

    return 0;
}