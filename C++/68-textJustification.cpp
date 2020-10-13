#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    if (maxWidth <= 0) return res;
    int i = 0, j = 0;
    while (j != words.size()) {
        int len = -1;
        while (j < words.size() && len + words[j].size() + 1 <= maxWidth) {
            len += words[j].size() + 1;
            j++;
        }
        int space = maxWidth - len + j - i - 1;
        int k = i;
        while (space) {
            words[k++] += " ";
            space--;
            if (j != words.size() && (k == j - 1 || k == j)) k = i;
            if (j == words.size() && k == j) k = j - 1;
        }
        string line = "";
        for (int l = i; l < j; l++) line += words[i];
        res.push_back(line);
        i = j;
    }
    return res;
}