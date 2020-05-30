#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    if (ratings.empty()) {
        return 0;
    }
    int n = ratings.size();
    if (n == 1) {
        return 1;
    }
    vector<int> candies(n, 0);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int sum = n;
    for (auto it : candies) {
        sum += it;
    }
    return sum;
}