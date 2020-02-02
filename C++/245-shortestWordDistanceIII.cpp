#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

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

    vector<int> s1;
    vector<int> s2;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1) {
            s1.push_back(i);
        }
        if (words[i] == word2 ) {
            s2.push_back(i);
        }
    }
    int i = 0;
    int j = 0;
    int res = words.size();
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] != s2[j])  {
            res = min(abs(s1[i] - s2[j]), res);
        }
        if (s1[i] <= s2[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << res << endl;

    return 0;
}