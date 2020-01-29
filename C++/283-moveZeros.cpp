#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    // nums.push_back(3);
    // nums.push_back(12);

    // solution 1
    // vector<int>::iterator iter;
    // iter = nums.begin();
    // for (int i = 0; i < nums.size(); i++) {
    //     if (*iter == 0) {
    //         nums.erase(iter);
    //         nums.push_back(0);
    //     } else {
    //         iter++;
    //     }
    // }

    // solution 2
    // for (int i = 0, j = 0; j < nums.size(); j++) {
    //     if (nums[j] != 0) {
    //         swap(nums[i], nums[j]);
    //         i++;
    //     }
    // }

    // solution 3
    int j = 0;
    for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
        if (*iter != 0) {
            nums[j] = *iter;
            j++;
        }
    }
    while (j < nums.size()) {
        nums[j] = 0;
        j++;
    }


    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }

    return 0;
}