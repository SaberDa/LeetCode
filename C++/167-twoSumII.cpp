#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;

    int l = 0;
    int r = nums.size() - 1;
    int res;

    while (l < r) {
        res = nums[l] + nums[r];
        if (res == target) {
            cout << l << " " << r << endl;
            break;
        } else if (res > target) {
            r--;
        } else {
            l++;
        }
    }
    return 0;

}