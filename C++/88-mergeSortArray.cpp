#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);
    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);
    int m, n;

    m = 3;
    n = 3;

    if (nums1.empty()) {
        sort(nums2.begin(), nums2.begin()+n);
        nums1 = nums2;
    }
    if (nums2.empty()) {
        sort(nums1.begin(), nums1.begin()+m);
    }

    for (int i = 0; i < n; i++) {
        nums1[m+i] = nums2[i];
    }
    sort(nums1.begin(), nums1.begin()+m+n);

    for (int i = 0; i < m+n; i++) {
        cout << nums1[i] << endl;
    }

    return 0;
}