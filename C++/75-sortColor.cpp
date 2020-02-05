#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);

    // use the method of bucket sort
    // the number 0 must be the front
    // and the number 2 must be the last
    // so we just move all 0 to the front,
    // and move all 2 to the last
    // the mid is the left 1

    for (int i = 0, j = 0, k = nums.size()-1; j <= k; ) {
        if (nums[j] == 0) {
            swap(nums[i], nums[j]);
            i++;
            j++;
        } else if (nums[j] == 2) {
            swap(nums[j], nums[k]);
            k--;
        } else {
            j++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}