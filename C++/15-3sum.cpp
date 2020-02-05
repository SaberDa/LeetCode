#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }
        sort(nums.begin(), nums.end());//nlgn
        
    for (int i = 0; i <= nums.size()-3; i++) {
        while(i > 0 && i <= nums.size()-3 && nums[i] == nums[i-1]){i++;}
        int m = i+1;
        int r = nums.size() - 1;
        int res1 = 0 - nums[i];
        while(m < r) {
            int res2 = nums[m] + nums[r];
            if (res1 == res2) {
                result.push_back({nums[m], nums[r], nums[i]});
                while (m<r && nums[r] == nums[r-1]) {
                   r--;
                }
                while (m<r && nums[m] == nums[m+1]) {
                   m++;
                }
                m++;
                r--;
               // break;
            } else if (res2 > res1) {
               r--;
           } else {
                m++;
           }

        }
    }

        return result;
    }
};

int main() {

    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(4);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(-5);
    nums.push_back(4);
    nums.push_back(0);
    int target = 0;


    // sort(nums.begin(), nums.end());

    // for (int i = 0; i < nums.size(); i++) {
    //     int l = i;
    //     int m = i+1;
    //     int r = nums.size() - 1;
    //     int res1 = target - nums[l];
    //     while (m < r) {
    //         int res2 = nums[m] + nums[r];
    //         if (res2 == res1) {
    //             cout << nums[l] << " " << nums[m] << " " << nums[r] << endl;
    //             break;
    //         } else if (res2 > res1) {
    //             r--;
    //         } else {
    //             m++;
    //         }
    //     }
    // }

    // two pointers
    // first sort the input vector
    // then fix one element, 
    // and choose the next element and the last element as the pointers
    // move them
    // if the three elements' sum equals zero, 
    // then push the three elements and move the both of pointers
    // else if sum larger than the zero, 
    // then move the left point
    // else if sum less than the zero,
    // then move the right point
    // remember to jump over the duplicate elements, all of three elements

    vector<vector<int>> res;
    if (nums.size() < 3) {
        return 0;
    }
    if ((nums.size() == 3) && (nums[0]+nums[1]+nums[2] == 0)) {
        res.push_back({nums[0], nums[1], nums[2]});
        return 0;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i <= nums.size()-3; i++) {
        while(i > 0 && i <= nums.size()-3 && nums[i] == nums[i-1]){i++;}
        int m = i+1;
        int r = nums.size() - 1;
        while(m < r) {
            if (nums[m]+nums[r]+nums[i] == 0) {
                res.push_back({nums[m], nums[r], nums[i]});
                while (m<r && nums[r] == nums[r-1]) {
                   r--;
                }
                while (m<r && nums[m] == nums[m+1]) {
                   m++;
                }
                m++;
                r--;
               // break;
            } else if (nums[m]+nums[r]+nums[i] > 0) {
               r--;
           } else {
                m++;
           }

        }
    }

    // for(int index = 0; index <= nums.size()-3; index++){
    //         while(index > 0 && index <= nums.size()-3 && nums[index] == nums[index-1]){index++;}
    //         int i = index+1;
    //         int j = nums.size()-1;
    //         while(i < j){
    //             if(nums[i] + nums[j] + nums[index] == 0){
    //                 res.push_back({nums[i], nums[j], nums[index]});
    //                 while(i<j && nums[i] == nums[i+1]){i++;}
    //                 while(i<j && nums[j] == nums[j-1]){j--;}
    //                 i++; j--;
    //             }
    //             else if(nums[i] + nums[j] + nums[index] > 0){
    //                 j--;
    //             }else{
    //                 i++;
    //             }
    //         }
    //     }

    

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }


    return 0;
}