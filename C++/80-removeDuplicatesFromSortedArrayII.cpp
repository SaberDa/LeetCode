#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums = { 0,0,1,1,1,1,2,3,3 };

    // solution 1
    // for (auto i = nums.begin(); i < nums.end(); i++) {
    //     while (count(nums.begin(), nums.end(), *i) > 2) {
    //         nums.erase(find(nums.begin(), nums.end(), *i));
    //     }
    // }

    // solution 2
    for (auto i = nums.begin(); i < nums.end() - 2; i++) {
        if (*i == *(i+1) && *i == *(i+2)) {
            nums.erase(i+2);
            i--;
        }
    }
    
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << " " << endl;
    cout << nums.size() << endl;

    return 0;
}