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

    // solution 1
    // just insert the second vector into the first vector
    // then sort the first vector
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

    // solution 2
    // because both of two vectors are sorted
    // we begin form the largest one
    // we pike up the larger element from the end of first and second vecotr
    // then insert it into the end of first element

    // for (int i = m - 1, j = n - 1; j >= 0;) {
    //      if (i <= 0 || nums1[i] < nums2[j]) {
    //          nums1[i+j+1] = num2[j];
    //          j--;
    //      } else {
    //          nums1[i+j+1] = nums1[i];
    //          i--;
    //      }   
    // } 
    
    return 0;
}