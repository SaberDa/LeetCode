#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    // nums.push_back(2);
    nums.push_back(-2);
    nums.push_back(3);
    nums.push_back(-4);
    // nums.push_back(-2);
    // nums.push_back(0);
    // nums.push_back(-1);

    if (nums.empty()) {
        return 0;
    }

    int cMax = nums[0];
    int cMin = nums[0];
    int maxR = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int p1 = cMax * nums[i];
        int p2 = cMin * nums[i];
        cMax = max(nums[i], max(p1, p2));
        cMin = min(nums[i], min(p1, p2));
        maxR = max(nums[i], cMax);
    }


    cout << maxR << endl;

    return 0; 

}