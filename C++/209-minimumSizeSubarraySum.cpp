#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2147483647

int main() {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(4);
    // nums.push_back(3);
    int s = 3;

    if (nums.empty()) {
        return 0;
    }

    int first = 0;
    int last = first;
    int sum = 0;
    int length = MAX;
    while (last < nums.size()) {
        sum += nums[last];
        last++;
        while (sum >= s) {
            length = min(length, last-first);
            sum -= nums[first];
            first++;
        }
    }
    length = (length == MAX ? 0 : length);

    cout << length << endl;

    return 0;
}
