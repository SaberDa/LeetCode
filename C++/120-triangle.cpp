#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<vector<int>> triangle;
    triangle.push_back({ 2 });
    triangle.push_back({ 3,4 });
    triangle.push_back({ 6,5,7 });
    triangle.push_back({ 4,1,8,3 });

    int n = triangle.size();
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    cout << triangle[0][0] << endl;


    return 0;
}
