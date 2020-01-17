#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int>& nums, int i, int j) {
    int max = i;
    while(i < j) {
        if (nums[max] < nums[i+1]) {
            max = i+1;
        }
        i++;
    }
    return max;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    int k = 3;

    vector<int> res;

    if (nums.empty()) {
        return 0;
    }
    
    int first = 0;
    int last = k-1;
    while (last < nums.size()) {
        int max = compare(nums, first, last);
        res.push_back(nums[max]);
        first++;
        last++;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;

}