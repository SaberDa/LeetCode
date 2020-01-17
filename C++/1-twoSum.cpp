#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    int target;

    int num1 = 0;
    int num2 = 0;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(15);
    target = 6;



    // for (int i = 0; i < nums.size(); i++) {
    //     auto it = find(nums.begin(), nums.end(), target-nums[i]);
    //     if (it != nums.end()) {
    //         num1 = i;
    //         num2 = &*it - &nums[0];
    //         if (num1 != num2) {
    //             cout << num1 << " " << num2 << endl;
    //             break;
    //         }

    //     }
    // }

    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = nums.size()-1; j != i; j--) {
    //         if (nums[i] + nums[j] == target) {
    //             num1 = i;
    //             num2 = j;
    //             cout << num1 << " " << num2 << endl;
                
    //         } 
    //     }
    // }


    
}