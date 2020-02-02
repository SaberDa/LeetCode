#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            temp[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) {
        int i1 = 0;
        int i2 = 0;
        int res = INT_MAX;
        int size1 = temp[word1].size();
        int size2 = temp[word2].size();
        while (i1 < size1 && i2 < size2) {
            res = min(res, abs(temp[word1][i1] - temp[word2][i2]));
            if (temp[word1][i1] < temp[word2][i2]) {
                i1++;
            } else {
                i2++;
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<int> > temp;
};

int main() {

    vector<string> words;
    words.push_back("practice");
    words.push_back("makes");
    words.push_back("perfect");
    words.push_back("coding");
    words.push_back("makes");

    string word1;
    string word2;

    word1 = "coding";
    word2 = "practice";

    WordDistance* obj = new WordDistance(words);
    int ans = obj->shortest(word1, word2);

    cout << ans << endl;

    return 0;
}