#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(4);

    int i = 0;
    int j = (nums.size() + 1) / 2;
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int k = 0; k < nums.size(); k++) {
        if (k % 2 == 0) {
            nums[k] = sorted[i];
            i++;
        } else {
            nums[k] = sorted[j];
            j++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}