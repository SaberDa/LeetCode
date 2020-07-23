#include <iostream>
#include <vector>

using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> temp = heights;
    int res = 0;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] != heights[i]) res++;
    }
    return res;
}