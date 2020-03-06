#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;

    // solution 1
    // for (auto i = nums.begin(); i < nums.end(); i++) {
    //     if (*i == val) {
    //         nums.erase(i);
    //         i--;
    //     }
    // }

    // solution 2
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            j++;
        }
    }

    nums.resize(j);

    for (auto i : nums) {
        cout << i << endl;
    }
    cout << nums.size() << endl;

    return 0;
}