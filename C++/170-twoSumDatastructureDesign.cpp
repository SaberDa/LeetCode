#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class TwoSum {
// private:
//     vector<int> sum;
// public:
//     TwoSum() {
//         sum.reserve(1000);
//     }

//     void add(int number) {
//         sum.push_back(number);
//     }

//     bool find(int value) {
//         if (sum.empty()) {
//             return false;
//         }
//         sort(sum.begin(), sum.end());
//         for (int i = 0, j = sum.size() - 1; i != j;) {  
//             if (sum[i] + sum[j] > value) {
//                 j--;
//             } else if (sum[i] + sum[j] < value) {
//                 i++;
//             } else {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class TwoSum {
private:
    unordered_map<int, int> mp;
public:
    TwoSum() {}

    void add(int number) {
        mp[number]++;
    }

    bool find(int value) {
        if (mp.empty()) {
            return false;
        }
        for (auto it : mp) {
            if ((mp.count(value - it.first)) && ((it.first != value - it.first) || it.second > 1)) {
                return true;
            }
        }
        return false;
    }
};