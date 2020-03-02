#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> digits;
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(9);

    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            for (auto x : digits) {
                cout << x << endl;
            }
            return 0;
        }
    }
    digits.emplace(digits.begin(), 1);
    for (auto x : digits) {
        cout << x << endl;
    }

    return 0;
}