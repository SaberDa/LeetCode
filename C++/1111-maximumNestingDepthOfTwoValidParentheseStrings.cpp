#include <iostream>
#include <vector>

using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    vector<int> res;
    int depth = 0;
    for (auto c : seq) {
        if (c == '(') depth++;
        res.push_back(depth % 2);
        if (c == ')') depth--;
    }
    return res;
}