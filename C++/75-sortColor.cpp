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