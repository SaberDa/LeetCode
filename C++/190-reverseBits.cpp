#include <isotream>
#include <string>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    string temp = bitset<32>(n).to_string();
    reverse(temp.begin(), temp.end());
    return (uint32_t) bitset<32>(temp).to_ulong();
}