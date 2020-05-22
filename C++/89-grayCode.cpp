#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// use bitset
vector<int> grayCode(int n) {
    bitset<32> bits;
    vector<int> res;
    helper(bits, res, n);
    return res;
}

void helper(bitset<32>& bits, vector<int>& res, int n) {
    if (n == 0) {
        res.push_back(bits.to_ulong());
        return;
    }
    helper(bits, res, n - 1);
    bits.flip(n - 1);
    helper(bits, res, n - 1);
}
