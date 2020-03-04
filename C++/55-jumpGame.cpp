#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums = { 0 };

    bool res = false;
    int target = 0;
    
    if (nums.size() < 2) {
        return 0;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (target < i) {
            break;
        }
        target = max(target, i+nums[i]);
        if (target >= nums.size() -1) {
            res = true;
            cout << res << endl;
            cout << i << endl;
            return 0;
        }
    }



    cout << res << endl;

    return 0;
}