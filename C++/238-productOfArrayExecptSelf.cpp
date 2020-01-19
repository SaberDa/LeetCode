#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);


    vector<int> res;
    if (nums.empty()) {
        return 0;
    }
    int sum = 1;
    res.push_back(1);
    for (int i = 1; i< nums.size(); i++) {
        sum *= nums[i-1];
        res.push_back(sum);
    }
    sum = 1;
    res[nums.size()-1] *= sum;
    for (int i = nums.size()-2; i>=0; i--) {
        sum *= nums[i+1];
        res[i] *= sum;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}