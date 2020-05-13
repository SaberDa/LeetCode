#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// solution 1 
// use hash table
class WordDictionary {
private:
    unordered_map<int, vector<string>> dict;
    bool isEqual(string a, string b) {
        for (int i = 0; i < a.size(); i++) {
            if (b[i] == '.') {
                continue;
            }
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
public:
    WordDictionary() {

    }

    void addWord(string word) {
        dict[word.size()].push_back(word);
    }

    bool search(string word) {
        for (auto s : dict[word.size()]) {
            if (isEqual(s, word)) {
                return true;
            }
        }
        return false;
    }
};