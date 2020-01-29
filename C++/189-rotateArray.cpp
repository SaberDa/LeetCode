#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    for (int i = 1; i <= 7; i++) {
        nums.push_back(i);
    }
    int k;
    k = 3;

    k = k % nums.size();
    if (nums.empty()) {
        return 0;
    }
    // solution 1
    // reverse(nums.begin(), nums.end()-k);
    // reverse(nums.end()-k, nums.end());
    // reverse(nums.begin(), nums.end());

    // solution 2
    // rotate(nums.begin(), nums.end()-k, nums.end());

    // solution 3
    nums.insert(nums.begin(), nums.end()-k, nums.end());
    nums.erase(nums.end()-k, nums.end());

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}
