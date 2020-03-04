#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {   

    vector<int> prices = { 3,2,6,5,0,3 };

    if (prices.empty()) {
        return 0;
    }
    int minP = prices[0];
    int price = 0;
    for (int i = 1; i < prices.size(); i++) {
        minP = min(minP, prices[i]);
        price = max(price, prices[i] - minP);
    }

    cout << price << endl;


    return 0;
}