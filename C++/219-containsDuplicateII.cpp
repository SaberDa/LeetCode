#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(99);
    nums.push_back(99);
    int k = 2;

    bool res = false;

    if (nums.empty()) {
        return 0;
    }

    unordered_map<int, int> m;



    for (int i = 0; i < nums.size(); i++) {
        if (m.count(nums[i])) {
            if (i-m[nums[i]] <= k) {
                res = true;
            }
            m[nums[i]] = i;
        } else {
            m[nums[i]] = i;
        }
    }

    cout << res << endl;


}