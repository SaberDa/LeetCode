#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);


    // two pointers
    // every time move one of the pointers,
    // first compare the current result with the old result
    // then length minus 1
    // compare two pointers and move
    int res = 0;
    int length = height.size() - 1;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
        res = max(res, min(height[l], height[r]) * length);
        length--;
        if (height[l] <= height[r]) {
            l++;
        } else {
            r--;
        }
    }
    
    cout << res << endl;


    return 0;
}