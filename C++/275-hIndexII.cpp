#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> citations = { 0,1,3,5,6 };

    if (citations.empty()) {
        return 0;
    }

    int i  = 0;
    int j = citations.size() - 1;
    while (j >= 0 && citations[j] > i) {
        i++;
        j--;
    }

    cout << i << endl;


    return 0;
}