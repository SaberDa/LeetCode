#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> citations = { 0,0 };

    if (citations.empty()) {
        return 0;
    }

    sort(citations.rbegin(), citations.rend());

    int i = 0;
    while (i < citations.size() && citations[i] > i) {
        i++;
    }

    cout << i << endl;



    return 0;
}