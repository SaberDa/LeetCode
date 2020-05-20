#include <isotream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    /*
     * Number:   1  10  100  1000  5  50  500  4   9    40  90  400  900
     * Notation: I  X    C    M    V   L   D   IV  IX   XL  XC  CD    CM
    */

    const vector<pair<int, string>> dic = {{1, "I"},{4, "IV"}, {5, "V"}, 
											{9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
											{100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
    string res = "";
    auto it = dic.end() - 1;
    while (num && it != dic.begin() - 1) {
        if (num >= it->first) {
            num -=it->first;
            res += it->second;
        } else {
            it--;
        }
    }
    return res;
}