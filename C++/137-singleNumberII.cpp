#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Let nums=[2,2,3,2]
Start algorithm
nums[0] = 2 (10)
nums[1] = 2 (10)

nums[0] = 10 & 10 = 10 (twos=(sum of two units for every rank)) 
nums[1] = 10 ^ 10 = 00 (units)
now we have 2 bits in second rank and 0 bits in first rank

one iteration of the loop
nums[2] = 3 (11)

nums[2] = nums[2] ^ nums[1] = 11 ^ 00 = 11 (units)
nums[1] = nums[2] & nums[1] = 11 & 00 = 00 (twos)

nums[0] ^ nums[2] = 10 ^ 11 = 01  <- this operation clear ranks that have three units
(nums[0] ^ nums[2]) & nums[0]  = 01 & 10 = 00 <- extract twos that were not cleared
nums[1] = nums[1] | (nums[0] ^ nums[2]) & nums[0] = 00 | 00 = 00 <- sum new twos and old twos
nums[2] = (nums[0] ^ nums[2]) & nums[2] = 01 & 11 = 01 <- extract units that were not cleared

after that iteration we have 0 bits in second rank and 1 bit in first rank

and so on.
*/
int singleNumberXOR(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    // XOR is a reverse operation, so we can avoid using of additional variable
    nums[1] ^= nums[0];
    nums[0] &= (nums[1] ^ nums[0]);

    for (int i = 2; i < nums.size(); i++) {
        // (nums[i] ^ nums[i - 1]) is just a nums[i] = 11, it is done also for avoid using additional variable
        nums[i] = nums[i] ^ nums[i - 1];
        nums[i - 1] &= (nums[i] ^ nums[i - 1]);
        nums[i - 1] |= (nums[i - 2] ^ nums[i]) & nums[i - 2];
        nums[i] = (nums[i - 2] ^ nums[i]) & nums[i];
    }
    return nums.back();
}

int singleNumber2(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    int ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] == nums[i + 2]) {
            i += 2;
        } else {
            return nums[i];
        }
    }
    return nums.back();
}

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto it : nums) {
        mp[it]++;
    }
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return 0;
}