#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int res = 1;
    for (auto x : flowerbed) {
        if (x == 0) res++;
        else {
            n -= res ? (res - 1) / 2 : 0;
            res = 0;
        }
    }
    n -= res / 2;
    return n <= 0;
}