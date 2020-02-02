#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    vector<string> words;
    words.push_back("practice");
    words.push_back("makes");
    words.push_back("perfect");
    words.push_back("coding");
    words.push_back("makes");
    string word1;
    string word2;

    word1 = "makes";
    word2 = "makes";

    // greaty algorithm
    int i1 = -1;
    int i2 = -2;
    int res = words.size();
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1 && i1 != i2) {
            i1 = i;
        } else if (words[i] == word2 && i1 != i2) {
            i2 = i;
        }
        if (i1 != -1 && i2 != -2) {
            res = min(res, abs(i2 - i1));
        }
    }

    cout << res << endl;

    return 0;
}