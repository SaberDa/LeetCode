#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> prices = { 1,2,3,4,5 };

    if (prices.empty()) {
        return 0;
    }

    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
        }
    }
    cout << profit << endl;

    return 0;
}  