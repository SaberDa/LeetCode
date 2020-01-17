#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    int res = nums[0];
    int maxR = res;

    for (int i = 1; i < nums.size(); i++) {
        res = max(nums[i], nums[i]+res);
        maxR = max(res, maxR);
    } 

    cout << maxR <<endl;

    return 0;


}