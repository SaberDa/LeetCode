#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    vector<int> prices = { 3,3,5,0,0,3,1,4 };

    if (prices.empty()) {
        return 0;
    }

    int buyFisrt = -1 * prices[0];
    int sellFirst = 0;
    int buySecond = INT_MIN;
    int sellSecond = 0;

    for (int i = 1; i < prices.size(); i++) {
        buyFisrt = max(buyFisrt, -1 *prices[i]);
        sellFirst = max(sellFirst, prices[i] + buyFisrt);
        buySecond = max(buySecond, sellFirst - prices[i]);
        sellSecond = max(sellSecond, buySecond + prices[i]);
    }

    cout << sellSecond << endl;

    return 0;
}
