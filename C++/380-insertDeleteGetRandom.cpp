#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

// solution 1, use the unordered_set
// class RandomizedSet {
// private:
//     unordered_set<int> nums;
// public:
//     RandomizedSet() {

//     }

//     bool insert(int val) {
//         auto iter = nums.find(val);
//         if (iter == nums.end()) {
//             nums.emplace_hint(iter, val);
//             return true;
//         }
//         return false;
//     }

//     bool remove(int val) {
//         auto iter = nums.find(val);
//         if (iter != nums.end()) {
//             nums.erase(iter);
//             return true;
//         }
//         return false;
//     }

//     int getRandom() {
//         int shift = rand() % nums.size();
//         auto res = nums.begin();
//         advance(res, shift);
//         return *res;
//     }
// };

// solution 2, use the unordered_map
#include <unordered_map>

class RandomizeSet {
private:
    unordered_map<int, int> nums;
public:
    RandomizeSet() {

    }

    bool insert(int val) {
        if (nums.find(val) == nums.end()) {
            nums[val] = val;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (nums.find(val) != nums.end()) {
            nums.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        int shift = rand() % nums.size();
        auto res = nums.begin();
        advance(res, shift);
        return res->first;
    }
};

// int main() {

//     unordered_map<int, int> temp;
//     temp.insert({1, 2});
//     temp.insert({3, 5});
//     temp.insert({7, 10});
//     temp.insert({111, 22});
//     cout << temp.size() << endl;
//     cout << temp.bucket_count() << endl;
//     cout << temp.bucket_size(6) << endl;

//     return 0;
// }