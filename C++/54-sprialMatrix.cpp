#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> matrix;
    matrix.push_back({2, 5});
    matrix.push_back({8, 4});
    matrix.push_back({0, -1});


    // set the bound of four corners
    // each move push the element from the min to max or from max to min
    // then min++ or max--
    // notice: 
    // when we push the element from the right to left or from the bottom to top
    // we should judge the relationship of the min and max again
    // because they may cross the border during the above ecexutions

    vector<int> res;
    if (matrix.empty()) {
        return 0;
    }
    int rMin = 0;
    int rMax = matrix.size()-1;
    int cMin = 0;
    int cMax = matrix[0].size() - 1;

    while (rMin <= rMax && cMin <= cMax) {
        for (int i = cMin; i <= cMax; i++) {
            res.push_back(matrix[rMin][i]);
        }
        rMin++;
        for (int i = rMin; i <= rMax; i++) {
            res.push_back(matrix[i][cMax]);
        }
        cMax--;
        for (int i = cMax; i >= cMin && rMin <= rMax; i--) {
            res.push_back(matrix[rMax][i]);   
        }
        rMax--;
        for (int i = rMax; i >= rMin && cMin <= rMax; i--) {
            res.push_back(matrix[i][cMin]);
        }
        cMin++;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " " ;
    }
 

    return 0;
}