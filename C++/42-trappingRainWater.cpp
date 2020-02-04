#include <iostream>
#include <vector>

using namespace std;

// using two pointers 
// find the current left max value and right max value
// if next value is smaller than the max value
// then it can trap water = (max -current value)
// if next valus is latger than the max value
// then reflesh the max value equals current value

int main() {

    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);

    int res = 0;
    if (height.empty()) {
        return res;
    }
    int l = 0;
    int r = height.size() - 1;
    int lMax = height[l];
    int rMax = height[r];
    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] >= lMax) {
                lMax = height[l];
            } else {
                res += lMax - height[l];
            }
            l++;
        } else {
            if (height[r] >= rMax) {
                rMax = height[r];
            } else {
                res += rMax - height[r];
            }
            r--;
        }
    }

    cout << res << endl;

    return 0;
}