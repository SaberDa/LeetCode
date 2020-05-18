#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> res;
    if (arr.empty()) {
        return res;
    }
    if (k > arr.size()) {
        return res;
    }

    if (x < arr[0]) {
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    if (x > arr[arr.size() - 1]) {
        return vector<int>(arr.begin() + arr.size() - k, arr.end());
    }

    int lo = 0;
    int hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (x == arr[mid]) {
            lo = mid;
            break;
        } else if (x < arr[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    int cur = lo;
    int left = cur - 1;
    int right = cur;
    while (k > 0) {
        if (left >= 0 && right < arr.size()) {
            if ((arr[right] - x ) >= (x - arr[left])) {
                res.push_back(arr[left]);
                left--;
            } else {
                res.push_back(arr[right]);
                right++;
            }
        } else if (right < arr.size()) {
            res.push_back(arr[right]);
            right++;
        } else if (left >= 0) {
            res.push_back(arr[left]);
            left--;
        }
        k--;
    }
    sort(res.begin(), res.end());
    return res;
}