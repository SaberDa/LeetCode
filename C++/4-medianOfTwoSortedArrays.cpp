#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    if (m == 0) {
        if (n & 1 == 1) {
            return nums2[n/2];
        } else {
            return (nums2[n/2] + nums2[n/2-1]) / 2.0;
        }
    }
    if (n == 0) {
        if (m & 1 == 1) {
            return nums1[m/2];
        } else {
            return (nums1[m/2] + nums1[m/2-1]) / 2.0;
        }
    }

    int left = 0;
    int right = m;
    int mid = (m + n + 1) / 2;

    while (left <= right) {
        int i = (left + right) / 2;
        int j = mid - i;
        if (i < m && nums2[j-1] > nums1[i]) {
            left = i + 1;
        } else if (i > 0 && nums1[i-1] > nums2[j]) {
            right = i - 1;
        } else {
            int maxLeft = 0;
            int minRight = 0;
            if (i == 0) {
                maxLeft = nums2[j-1];
            } else if (j == 0) {
                maxLeft = nums1[i-1];
            } else {
                maxLeft = max(nums1[i-1], nums2[j-1]);
            }

            // maxLeft = (i == 0) ? nums2[j-1] : (j == 0) ? nums1[i-1] : max(nums1[i-1], nums2[j-1]);

            if ((m+n) / 2 == 1) {
                return maxLeft;
            }
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = min(nums1[i], nums2[j]);
            }
            return (maxLeft + minRight) / 2.0;
        }
        
    }
    return 0;
    
}

int main() {

    vector<int> nums1 = { 100001 };
    vector<int> nums2 = { 100000 };

    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;

    return 0;
}