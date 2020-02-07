#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    // solution 1
    // two pointers
    // use pointers to present the left and right histogram
    // make sure the min height is the chosen one
    // move the left and right pointers until they are less then the mid
    // the area is mid.height*(right-left-1)
    // repeat and find the max area

    // int res = 0;
    // int left;
    // int right;
    // for (int i = 0; i < heights.size(); i++) {
    //     left = i - 1;
    //     right = i + 1;
    //     while (left >= 0 && heights[left] >= heights[i]) {
    //         left--;
    //     }
    //     while (right < heights.size() && heights[right] >= heights[i]) {
    //         right++;
    //     }
    //     res = max(res, (right - left - 1) * heights[i]);
    // }
    
    // cout << res << endl;

    // solution 2
    // monotonic stack
    // make sure the elements in stack is monotonic increase
    // if next element is larger than the top element, push it
    // if next element is less than the top element,
    // then pop the top element and calculate the area
    int res = heights[0];
    stack<int> s;
    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
        } else {
            int cur = s.top();
            s.pop();
            res = max(res, (s.empty() ? i : i - s.top() - 1) * heights[cur]);
        }
    }

    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        res = max(res, (s.empty() ? i : i - s.top() - 1) * heights[cur]);
    }

    cout << res << endl;

    return 0;
}