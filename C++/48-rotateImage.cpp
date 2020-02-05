#include <vector>
#include <iostream>

using namespace std;

int solution1() {
    vector<vector<int>> matrix;
    matrix.push_back({5, 1, 9, 11});
    matrix.push_back({2, 4, 8, 10});
    matrix.push_back({13, 3, 6, 7});
    matrix.push_back({15, 14, 12, 16});

    // first transcope
    // next exchange

    if (matrix.empty()) {
        return 0;
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[i].size(); j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size()/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix[i].size()-j-1];
            matrix[i][matrix[i].size()-j-1] = temp;
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << " " << endl;
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix;
    matrix.push_back({5, 1, 9, 11});
    matrix.push_back({2, 4, 8, 10});
    matrix.push_back({13, 3, 6, 7});
    matrix.push_back({15, 14, 12, 16});

    // use the math way to solve
    // every time move the four corners
    // the left top corner becomes the right top corner
    // the right top corner becomes the right bottom corner
    // the right bottom corner becomes the left bottom corner
    // the left corner becomes the left top corner

    int n = matrix.size() - 1;
    for (int i = 0; i < matrix.size()/2; i++) {
        for (int j = i; j < n-i; j++) {
            int topLeft = matrix[i][j];
            int topRight = matrix[j][n-i];
            int bottomLeft = matrix[n-j][i];
            int bottomRight = matrix[n-i][n-j];
            matrix[i][j] = bottomLeft;
            matrix[j][n-i] = topLeft;
            matrix[n-i][n-j] = topRight;
            matrix[n-j][i] = bottomRight;
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << " " << endl;
    }
    return 0;

}