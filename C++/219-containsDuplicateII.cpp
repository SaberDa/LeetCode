#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    int k = 2;

    bool res = false;

    if (nums.empty()) {
        return 0;
    }

    for (int i = 0; i < nums.size() - k; i++) {
        if (nums[i] == nums[i+k]) {
            res = true;
            break;
        }
    }

    cout << res << endl;

    return 0;

}