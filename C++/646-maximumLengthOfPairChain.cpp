#include <iostream>
#include <vector>

using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    auto comp = [](vector<int>& a, vector<int>& b){return a[1] < b[1]; };
    sort(pairs.begin(), pairs.end(), comp);
    int count = 0;
    int end = INT_MIN;
    for (auto x : pairs) {
        if (x[0] > end) {
            end = x[1];
            count++;
        }
    }
    return count;
}