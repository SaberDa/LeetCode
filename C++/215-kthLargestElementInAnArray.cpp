#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    int k;

    k = 2;

    if (nums.empty()) {
        return 0;
    }

    sort(nums.begin(), nums.end(), greater<int>() );
    cout << nums[k-1] << endl;

    return 0;
}