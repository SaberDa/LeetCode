#include <string>
#include <vector>

using namespace std;

string getVertical(vector<string> &words, int col) {
    string res = "";
    for (int i = 0; i < words.size(); i++) {
        if (col < words[i].size()) res.push_back(words[i][col]);
    }
    return res;
}


bool validWordSquare(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        if (words[i] != getVertical(words, i)) return false;
    }
    return true;
}